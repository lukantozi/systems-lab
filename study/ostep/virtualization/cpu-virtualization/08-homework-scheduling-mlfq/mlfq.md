# OSTEP Ch. 8

source: https://github.com/remzi-arpacidusseau/ostep-homework

### Simulation tasks (mlfq.py):

1. Few randomly-generated problems with just two jobs and two queues.

```txt
jobs 2, queues 2
allotments for queue 0 and 1 is   1
quantum length for queue 0 and 1 is  10
boost 0, ioTime 0
stayAfterIO False, iobump False


Job List:
  Job  0: startTime   0 - runTime  12 - ioFreq   0
  Job  1: startTime   0 - runTime   6 - ioFreq   0

Answers:
    job 0 runs for 10 times
    job 1 runs for  6 times (finishes)
    job 0 runs for  2 times (finishes)

    response time: job 0 = 0; job 1 = 10
    turnaround time: job 0 = 18; job 1 = 16

(lost several simulations and records due to not saving file before powering off)
```

2. Reproduction of the examples in the chapter.

```txt
figure 8.2:         ./mlfq.py --jlist 0,200,0 -q 10 -c
figure 8.3 (left):  ./mlfq.py --jlist 0,180,0:100,20,0 -q 10 -c
figure 8.3 (right): ./mlfq.py --jlist 0,175,0:50,25,1 -i 5 -q 10 -S -c
figure 8.4 (left):  ./mlfq.py --jlist 0,150,0:100,50,1:100,50,1 -i 1 -q 10 -S -c
                    (arbitrary length for the job 0 to demonstrate it's starved)
figure 8.4 (right): ./mlfq.py --jlist 0,150,0:100,35,1:100,35,1 -i 1 -q 10 -S -B 10 -c
                    (setting -B to 100 would not give the right result as graph demanded;
                    -B 10 would correctly demonstrate what rules intended to achieve)
figure 8.5 (left):  ./mlfq.py --jlist 0,180,0:100,120,5 -i 1 -S -c
                    (approximate simulation, demonstrating general idea)
figure 8.5 (right): ./mlfq.py --jlist 0,180,0:100,120,5 -i 1 -c
                    (approximate simulation, demonstrating general idea)
figure 8.6:         
```

3. Parameters set so that scheduler acts like rr.

```txt
./mlfq.py --jlist 0,100,0:0,100,0 -n 1 -q 5 -c
```

4. Simulation wehre one job takes advantage of the older Rules 4a and 4b
(turned on with the -S flag) to game the scheduler and obtain 99% of the CPU
over a particular time interval.

```txt
./mlfq.py --jlist 0,100,0:30,30,9 -i 1 -q 10 -S -c
```

5. To make sure the job gets at least 5% of the CPU in a system with quantum
length of 10 ms in its highest queue, how often should one boost back to
the highest priority?

```txt
200ms
```
