# LMS-Verify

Using staging (via [LMS](http://github.com/TiarkRompf/virtualization-lms-core) -- see [tutorials](http://scala-lms.github.io/tutorials/)),
generate first-order verifiable C code from a higher-level counterpart in Scala.

Presentation with some highlights ([PDF](http://lampwww.epfl.ch/~amin/lms/verify-slides.pdf)).

POPL'17 paper ([PDF](http://lampwww.epfl.ch/~amin/pub/lms-verify.pdf)) and slides ([PDF](http://lampwww.epfl.ch/~amin/lms/lms-verify-popl.pdf)).

## C Verification

The generated C code is verified using `frama-c -wp` as follows:

```frama-c -wp -wp-rte -wp-prover CVC4,alt-ergo <file.c>```

All the files in the [`src/out`](src/out) directory should verify with this command, except those ending with `_bad.c` and except some `_overflow` `-rte` goals.

Other useful options: `-wp-skip-fct p` to skip verifying a function `p`, `-wp-timeout 50` to increase the timeout in case of flakiness.

TODO: Consider [VeriFast](https://github.com/verifast/verifast) as a backend. Does it have a better memory model and separation logic? To find out by trying C programs. Is it compatible with ACSL as used here to target Frama-C? Probably not entirely, if at all.

### Docs
* [Frama-C WP manual (PDF)](http://frama-c.com/download/frama-c-wp-manual.pdf)
* [ACSL tutorial (PDF)](http://frama-c.com/download/acsl-tutorial.pdf)
* [ACSL reference manual (PDF)](http://frama-c.com/download/acsl.pdf)

### Installation
* Install [CVC4](https://cvc4.cs.stanford.edu/downloads/).
* Install [Frama-C](http://frama-c.com/download.html) -- after installation, do `why3 config --detect` to configure the solvers -- without this extra step, examples that discharge to a backend will fail to verify!

## Lessons Learned

So far, the main take-away is that for verifying generic properties (such as no memory errors), generative programming patterns extend well to also generate specification and annotations. We can program with high-level abstractions including higher-order functions, and generate low-level first-order code that is easy to verify. Next, we investigate deep linguistic reuse, e.g. staging-time abstractions, to specify invariant and properties modularly, share source between target code and logic, and exploit high-level knowledge to automatically generate certain annotations. This should help alleviate the annotation burden when verifying more functional properties. Finally, we also consider the notion of "blame" in this generative setting.

### Completed Case Studies

#### Regular Expression Matchers

From a high-level regular expression matcher, written as a generic interpreter, generate low-level C code specialized to a specific regular expression. In each tested instance, the generated code is verified to be free of memory errors. This required very few, simple and generic annotations about loop invariants. ([code](src/test/scala/lms/verify/RegexTests.scala))

Fun fact: the generic interpreter comes from C ([original code with hand-written ACSL annotations](src/out/re.c)), but was translated to Scala for the LMS tutorials as a small example of the common generative pattern of turning an interpreter into a compiler ([tutorial page](http://scala-lms.github.io/tutorials/regex.html)), and now the LMS backend switched to generating C code (using Scala-like string idioms still).

#### HTTP Parser

We write a high-level HTTP parser, using a small staged parser combinator library, and generate low-level C code that validates HTTP responses at a fast rate -- ~1 millions items per second, which is competitive with hand-written optimized parsers such as [nginx/nodejs HTTP parser in C](https://github.com/nodejs/http-parser).
With little effort in the generator, the generated code is verified to be free of memory and overflow errors. This is significant as major HTTP servers have had serious security advisories ([nginx](https://cve.mitre.org/cgi-bin/cvename.cgi?name=cve-2013-2028), [Apache](https://cve.mitre.org/cgi-bin/cvename.cgi?name=cve-2002-0392)) related to chunked parsing. ([code](src/test/scala/lms/verify/ParserTests.scala))

### Case Studies in Progress

#### Generic Sorting
studies functional correctness, using type classes and other staging-time abstractions to be explicit about generic requirements and parametric by default. Principled generative programming and verification FTW. ([code](src/test/scala/lms/verify/SortingTests.scala))

(TODO: cleanup, use higher-order [blame](src/test/scala/lms/verify/BlameTests.scala) to fault comparator if not transitive)

#### Linear Algebra
studies inferring low-level loop properties and custom staging-time abstractions with domain-specific knowledge of invariants. Invariants can be composed, customized by staging-time logic invariants, and inferred thanks to sharing and re-using source fragment between code and logic target. ([code](src/test/scala/lms/verify/LinearAlgebraTests.scala))

(TODO: cleanup, implement more operations, e.g. transpose)

### Case Studies to Try Out

#### Functionally Correct Optimized Shonan Challenge
Implement a matrix vector product, where the matrix is known statically.
In the spec, you can spell out each entry in the known matrix, as well as the definition of matrix vector product.
In the implementation, you can optimize the matrix vector product, unrolling sparse rows and optimizing arithmetic operations (multipliying by 1 or 0, adding 0).
Verify that the optimized implementation still implements the matrix vector product. ([code](src/test/scala/lms/verify/ShonanTests.scala))

#### Functionally Correct String Matching Algorithms
Comparing naive string matching (as a spec) to optimized string matching like Knuth-Morris-Pratt.
The starting point is from this BRICS report [(PDF)](http://cs.au.dk/~danvy/DSc/06_BRICS-RS-04-40.pdf).
Verified functionally correct (equivalent to spec), except termination argument is missing.
([code](src/test/scala/lms/verify/KMPTests.scala))
([hand-coded example](src/out/kmp_aab.c))

#### Functionally Correct Optimized Regular Expression Matcher
Implement an optimized regular expression matcher, where the regular expression is known.
As a first step, you can do a naive compiler via a staged interpreter, but then you could also do a staged NFA to DFA exploration.
In the spec, you can specify regular expression matching in simple terms as an interpreter.
Verify that the optimized implementation still matches as specified by the spec.
([code for naive compiler](src/test/scala/lms/verify/CRegexTests.scala))
([code for NFA to DFA compiler](src/test/scala/lms/verify/AutomataTests.scala))
([hand-coded example](src/out/dfa_spec_aab.c))

#### Bidirectional Combinators and Round-Tripping Properties
At a high level, we might be able to specify parsing / unparsing (i.e., printing) once using bidirectional combinators,
and then stage these combinators.
Can we preserve the bidirectional properties, such as round-tripping (i.e., that parsing and printing are almost inverse), all the way to the generated code?

From [hand-coded example](src/bip_cesar1.c): the abstraction seems a bit leaky in terms of the separation verification. Maybe this can still be encapsulated nicely, and generalized, using appropriate blame when the cypher/decypher pair do not compose to the identity.
