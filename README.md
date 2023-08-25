This repository contains code for various branch predictors. These were written as part of a classroom exercise for the CS810: Advanced Computer Architecture course at IIT Dharwad.

# Branch Predictors
Some of the branch predictors implemented are:
- Bimodal Predictor
- Bimoal Predictor with n-bit saturating counters
- GAg Predictor
- GAp Predictor

Note: The various predictors are pushed to the repository as different commits.

# Testing
The predictors were tested using the setup provided at the [CSE240a Branch Predictor Project](https://cseweb.ucsd.edu/classes/wi12/cse240A-a/proj.html) page.

## Original README
Instructions:

1) Get a copy of the code from the class webpage

2) Make the predictor (run make in your working source directory).

3) Run the predictor
(bunzip2 -c -k ../traces/DIST-INT-1.bz2 | ./predictor)
where DIST-INT-1.bz is one of the trace files.
./predictor reads (in a binary format) from STDIN a trace
(decompressed with bzip2 on the fly). It outputs to STDOUT basic
statistics about how well the predictor did.

4) Create your own predictor.C file and predictor.h file (or modify
the existing ones).  Be sure to read the long comment at the beginning
of the provided predictor.h and follow it's directions.  Just make
sure your predictor implements the three functions exactly as their
specification reads (init_predictor, make_prediction, and
train_predictor).  The only two files of yours you will turn in are
predictor.h and predictor.C.  All other source files (and makefile)
will remain the same.

5) Submit your predictor.C and predictor.h files along with your
report (details of this specified on the webpage).  Email them to
marora@eng.ucsd.edu with subject line: "WI12 CSE240A Project 1"