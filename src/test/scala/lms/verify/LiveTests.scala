package lms.verify

class LiveTests extends TestSuite {
  val under = "live_"

  test("playground") {
    trait Program extends Dsl {
    }
    exec("playground", (new Program with Impl).code)
  }
}

// Example 1: mini shonan
// - playground for questions
// - shows virtualization of control structures (if, for)
// - loop unrolling based on run-time first-stage values
// - a bit of help in writing specs, dodge overflows
// - mention optimized functional correctness

// Example 2: bip cesar
// - shows an end to end example
// - recipe starts with an *small* _instance_ in low-level C (see out/bip_cesar1.c)
// - extract the verification and code recipe from example
// - abstract both in code generator
// - exploit shared logic and code, in addition to usual generative patterns
// - example also shows limitations of Frama-C, with leaky separation
// - issues at scale (e.g. with bigger sorting instances)
// - issue with seemingly simple challenge: define functionally correct matrix transposition
// - some work-arounds with inductive definition (go back to shonan MVP spec)

