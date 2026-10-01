# OSTEP Ch. 10

source: https://github.com/remzi-arpacidusseau/ostep-homework

### Simulation tasks (multi.py):

1. ./multi.py -n 1 -L a:30:200.

```txt
it takes 30 times to complete the job 'a'
```

2. ./multi.py -n 1 -L a:30:200 -M 300.

```txt
since working-set size fits in cache size, job will be run in
'warmup rate' after first cycle, so it will take 10 (normal) +
10 (halved due to warm state) = 20 times to complete the job 'a',
```

3. ./multi.py -n 1 -L a:30:200 -M 300 -T

```txt
second column (time left for the job) in the second cycle decreases twice
as much as second column in the first cycle, showcasing the 'warm state'
which runs the job twice as fastsecond column in the first cycle, showcasing the
'warm state' which runs the job twice as fast.
```

4. ./multi.py -n 1 -L a:30:200 -M 300 -T -C

```txt
cache becomes warm at time 9 (taking 10 times to warm up)
after increasing value of -w (>10), cache warms up later, taking
longer for the job to finish, and if value is decreased (<10), cache
becomes warm earlier, resulting in job finishing quicker.
```

5. ./multi.py -n 2 -L a:100:100,b:100:50,c:100:50

```txt
it takes 150 times to finish all three jobs (couldn't predict
correctly). it's worth mentioning that with the configuration
above warming up of the cache is never utilized effectively as jobs
are run from the global queue and the working set sum of
all jobs is greater than the default cache size, which doesn't
allow the job that warmed up its cache on the certain cpu
to use that warmness; after the job warms up its cache, before getting cpu again,
other two warm their own cache's (such is order for jobs using the cpu),
'cooling down' initial job's cache as they can't fit together due
to cache size limitation
```

6. ./multi.py -n 2 -L a:100:100,b:100:50, c:100:50 -A a:0,b:1,c:1

```txt
it will take max(10 + 45, 10 + 10 + 45 + 45) = 110 times to finish
all the jobs. due to assigning job 1 and 2 to cpu 1, their sum
of working set fits in the cache size of cpu 1, which enables
for both jobs to have cache warmed up, doubling the execution
speed.

after noticing that cpu 0 is idle for 50% of the time, adding
one of b or c to utilize cpu 0 too reduces total time spent to
finish all the jobs by 10, utilizing cpu 0 100% of the time
and cpu 1 95%.
```

7. ./multi.py -L a:100:100,b:100:100,c:100:100

```txt
`-m 50`
    `-n 1` -- takes 300 times
    `-n 2` -- takes 150 times
    `-n 3` -- takes 100 times

`-m 100'
    `-n 1` -- takes 300 times
    `-n 2` -- takes 150 times
    `-n 3` -- takes  55 times

in the last simulation performance increases in a super-linear
speedup manneer due to each job utilizing their warmed up caches,
doubling the execution speed.
```

8. ./multi.py -L a:100:100,b:100:50,c:100:50 -n 2 -p

```txt
flag -p enables per cpu scheduling queues. jobs are assigned in a rr/
first-fit manner and idle cpus may steal work from other queues

modifying peek interval (-P) changes outcome: decreasing its value
finds jobs quicker and total completion time decreases, while increasing it
makes stealing less frequent, prolonging job completion.

with more cpus, idle periods tend to be shorter and work is distributed
more finely and finer tuning of peek interval has less effect.
```
