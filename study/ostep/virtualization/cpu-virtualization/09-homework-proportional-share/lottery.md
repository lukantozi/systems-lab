# OSTEP Ch. 9

source: https://github.com/remzi-arpacidusseau/ostep-homework

### Simulation tasks (lottery.py):

1. solution to random seed 1:

```txt
job list, with the run time of each job: 
  Job 0 ( length = 1, tickets = 84 ) (0 - 83)
  Job 1 ( length = 7, tickets = 25 ) (84 - 108)   (0 - 24)
  Job 2 ( length = 4, tickets = 44 ) (109 - 152)  (25 - 68)

Random 651593 -> ticket 119 (of 153) -> run 2
    jobs: ( job:0 timeleft:1 tix:84 ) ( job:1 timeleft:7 tix:25) (* job:2 timeleft:4 tix:44)
Random 788724 -> ticket 9 (of 153) -> run 0
    jobs: (* job:0 timeleft:1 tix:84 ) ( job:1 timeleft:7 tix:25) ( job:2 timeleft:3 tix:44)
    --> job 0 is done at time 2
Random 93859 -> ticket 19 (of 69) -> run 1
    jobs: ( job:0 timeleft:0 tix:--- ) (* job:1 timeleft:7 tix:25) ( job:2 timeleft:3 tix:44)
Random 28347 -> ticket 57 (of 69) -> run 2
    jobs: ( job:0 timeleft:0 tix:--- ) ( job:1 timeleft:6 tix:25) (* job:2 timeleft:3 tix:44)
Random 835765 -> ticket 37 (of 69) -> run 2
    jobs: ( job:0 timeleft:0 tix:--- ) ( job:1 timeleft:6 tix:25) (* job:2 timeleft:2 tix:44)
Random 432767 -> ticket 68 (of 69) -> run 2
    jobs: ( job:0 timeleft:0 tix:--- ) ( job:1 timeleft:6 tix:25) (* job:2 timeleft:1 tix:44)
    --> job 2 is done at time 6
Random 762280 -> ticket ... -> run 1
    jobs: ( job:0 timeleft:0 tix:--- ) (* job:1 timeleft:6 tix:25) ( job:2 timeleft:0 tix:--- )
Random 2106
    jobs: ( job:0 timeleft:0 tix:--- ) (* job:1 timeleft:5 tix:25) ( job:2 timeleft:0 tix:--- )
Random 445387
    jobs: ( job:0 timeleft:0 tix:--- ) (* job:1 timeleft:4 tix:25) ( job:2 timeleft:0 tix:--- )
Random 721540
    jobs: ( job:0 timeleft:0 tix:--- ) (* job:1 timeleft:3 tix:25) ( job:2 timeleft:0 tix:--- )
Random 228762
    jobs: ( job:0 timeleft:0 tix:--- ) (* job:1 timeleft:2 tix:25) ( job:2 timeleft:0 tix:--- )
Random 945271
    jobs: ( job:0 timeleft:0 tix:--- ) (* job:1 timeleft:1 tix:25) ( job:2 timeleft:0 tix:--- )
    --> job 1 is done at time 12
```

2. Running two jobs with -l 10:1,10:100.

```txt
Due to large ticket ratio, job 0 will be starved in most cases.
Chance of job 0 running before job 1 at each particular quantum
slice is 0.99%. Such ticket imbalance renders lottery scheduling
useless.
```

3. When running with two jobs of length 100 and equal ticket alloca-
tions of 100 (-l 100:100,100:100), how unfair is the scheduler?
Run with some different random seeds to determine the (probabilis-
tic) answer; let unfairness be determined by how much earlier one
job finishes than the other.

```txt
seed 1 -- fairness -> 0.98
seed 2 -- fairness -> 0.95
seed 3 -- fairness -> 0.98
seed 4 -- fairness -> 0.99
seed 5 -- fairness -> 0.91
seed 6 -- fairness -> 0.96
seed 7 -- fairness -> 0.92

average fairness == 0.95
```

4. What happens to unfairness when -q gets larger?

```txt
fairness decreases as -q gets larger.
```
