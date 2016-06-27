# LMS-Verify

An early experiment using staging (via [LMS](http://github.com/TiarkRompf/virtualization-lms-core) -- see [tutorials](http://scala-lms.github.io/tutorials/)) to generate first-order verifiable C code from a higher-level counterpart.

## C Verification

The generated C code is verified using `frama-c -wp` as follows:

```frama-c -wp -wp-rte -wp-prover cvc4,alt-ergo -wp-alt-ergo-opt="-backward-compat" <file.c>```

All the files in the `src/out` directory should verify with this command, except those ending with `_bad.c` and except some `_overflow` `-rte` goals.

Other useful options: `-wp-skip-fct p` to skip verifying a function `p`, `-wp-timeout 50` to increase the timeout in case of flakiness.

### Docs
* [Frama-C WP manual (PDF)](http://frama-c.com/download/frama-c-wp-manual.pdf)
* [ACSL tutorial (PDF)](http://frama-c.com/download/acsl-tutorial.pdf)
* [ACSL reference manual (PDF)](http://frama-c.com/download/acsl.pdf)

### Installation
* Install CVC4, e.g. `brew install cvc4` on Mac OS X.
* [Frama-C installation](http://frama-c.com/install-aluminium-20160501.html) -- after installation, do `why3 config --detect` to configure the solvers -- without this extra step, examples that discharge to a backend will fail to verify!

## Lessons Learned

So far, the main take-away is that for verifying generic properties (such as no memory errors), generative programming patterns extend well to also generate specification and annotations. We can program with high-level abstractions including higher-order functions, and generate low-level first-order code that is easy to verify. Next, we plan to investigate how to use staging-time abstractions to specify invariant and properties modularly and exploit high-level knowledge to automatically generate certain annotations. This should help alleviate the annotation burden when veryfing more functional properties. Finally, we also consider the notion of "blame" in this generative setting.

### Completed Case Studies

#### Regular Expression Matchers

From a high-level regular expression matcher, written as a generic interpreter, generate low-level C code specialized to a specific regular expression. In each tested instance, the generated code is verified to be free of memory errors. This required very few, simple and generic annotations about loop invariants. ([code](src/test/scala/lms/verify/RegexTests.scala))

#### HTTP Parser

We write a high-level HTTP parser, using a small staged parser combinator library, and generate low-level C code that validates an HTTP response. The generated code is verified to be free of memory and overflow errors. ([code](src/test/scala/lms/verify/ParserTests.scala))
