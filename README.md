# lms-verify

An early experiment using staging (via [LMS](http://github.com/TiarkRompf/virtualization-lms-core)) to generate first-order verifiable C code from its higher-level counterpart.

## C Verification

The generated C code is verified using frama-c wp as follows:

```frama-c -wp -wp-rte <file.c>```

All the files in the `src/out` directory should verify with this command, except those ending with `_bad.c` and except some `_overflow` goals.

* [frama-c wp manual (PDF)](http://frama-c.com/download/frama-c-wp-manual.pdf)
* [acsl tutorial (PDF)](http://frama-c.com/download/acsl-tutorial.pdf)
* [acsl implementation in frama-c (PDF)](http://frama-c.com/download/acsl-implementation-Sodium-20150201.pdf)
* [frama-c installation](http://frama-c.com/install-sodium-20150201.html) -- after installation, do `why3 config --detect` to configure the solvers -- without this extra step, examples that discharge to a backend will fail to verify!
