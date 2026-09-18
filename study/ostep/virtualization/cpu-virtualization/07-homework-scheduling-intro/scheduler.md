# Homework (Simulation)

1. Compute the response time and turnaround time when running
three jobs of length 200 with the SJF and FIFO schedulers.

```
Here is the job list, with the run time of each job: 
  Job 0 ( length = 200.0 )
  Job 1 ( length = 200.0 )
  Job 2 ( length = 200.0 )

FIFO
---
job 0:
    response time    -- 0
    turnaround time -- 200

job 1:
    response time    -- 200
    turnaround time -- 400

job 2:
    response time    -- 400
    turnaround time -- 600

avg response time is:    (0 + 200 + 400) / 3   = 200
avg turnaraound time is: (200 + 400 + 600) / 3 = 400

SJF
---
job 0:
    response time    -- 0
    turnaround time -- 200

job 1:
    response time    -- 200
    turnaround time -- 400

job 2:
    response time    -- 400
    turnaround time -- 600

avg response time is:    (0 + 200 + 400) / 3   = 200
avg turnaround time is: (200 + 400 + 600) / 3 = 400
---

```

2. Now do the same but with jobs of different lengths: 100, 200, and
   300.

```
Here is the job list, with the run time of each job:
  Job 0 ( length = 100.0 )
  Job 1 ( length = 200.0 )
  Job 2 ( length = 300.0 )

FIFO
---
job 0:
    response time    -- 0
    turnaround time  -- 100

job 1:
    response time    -- 100
    turnaround time  -- 300

job 2:
    response time    -- 300
    turnaround time  -- 600

avg response time is:   (400) / 3  = 133.3
avg turnaround time is: (1000) / 3 = 333.3

SJF
---
job 0:
    response time    -- 0
    turnaround time  -- 100

job 1:
    response time    -- 100
    turnaround time  -- 300

job 2:
    response time    -- 300
    turnaround time  -- 600

avg response time is:   (400) / 3  = 133.3
avg turnaround time is: (1000) / 3 = 333.3
```

3. Now do the same, but also with the RR scheduler and a time-slice
of 1.

```
Here is the job list, with the run time of each job:
  Job 0 ( length = 100.0 )
  Job 1 ( length = 200.0 )
  Job 2 ( length = 300.0 )

RR + quantum = 1
---
job 0:
    response time    -- 0
    turnaround time  -- 298

job 1:
    response time    -- 1
    turnaround time  -- 499

job 2:
    response time    -- 2
    turnaround time  -- 600

avg response time is:   (3) / 3  = 1
avg turnaround time is: (300 + 500 + 600) / 3 ~= 465
```

4. For what types of workloads does SJF deliver the same turnaround
times as FIFO?

```
When jobs starting at the same tiem have equal or increasing lenght.
```

5. For what types of workloads and quantum lengths does SJF deliver
the same response times as RR?

```
RR and SJF will deliver same response time when the job lengths are
same and the quantum length also equals length of the each job.
```

6. What happens to response time with SJF as job lengths increase?
Can you use the simulator to demonstrate the trend?

```
As job lengths increase, response times will simply increase (after 
the first job), since it will reflect directly to the length of the
increased jobs; this conclusion comes with one caveat, that if we
increase length of the certain job, only jobs longer than that one
will suffer higher response time.
```

7. What happens to response time with RR as quantum lengths in-
crease? Can you write an equation that gives the worst-case re-
sponse time, given N jobs?

```
Response time with RR as qunatum lengths increase will also
increase. worst_case_rt = q * (N - 1);
```
