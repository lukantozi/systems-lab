# Homework (cpu-intro)

1. Run process-run.py with the following flags: -l 5:100,5:100.
What should the CPU utilization be (e.g., the percent of time the
CPU is in use?) Why do you know this? Use the -c and -p flags to
see if you were right.
> The percent of time the CPU is in use is 100%. Both processes' have
instructions that are CPU instructions only, CPU will be in use
first executing instructions of the first process, after completing
which, second process instructions will be completed. (correct)

2. Now run with these flags: ./process-run.py -l 4:100,1:0.
These flags specify one process with 4 instructions (all to use the
CPU), and one that simply issues an I/O and waits for it to be done.
How long does it take to complete both processes? Use -c and -p
to find out if you were right.
> To complete both processes in fact it takes 11 times: first,
the process 0 is being executed in CPU (RUNNING) while the process 1
is simply in READY mode. After 4 times, process 1 starts and runs
I/O (1 time in CPU), after which the process is blocked and waits for
I/O to finish, which takes 4 times, and then process 1 reclaims control
and 1 more time is spend to finish the process. (my initial answer was wrong
inferring that I/O of the process 1 will run in the background while
process 0 completes it's CPU instructions)

3. Switch the order of the processes: -l 1:0,4:100. What happens
now? Does switching the order matter? Why? (As always, use -c
and -p to see if you were right)
> Seems like switching order initiates process 0, which takes 1 time
to run I/O, after which the process gets blocked while I/O executes,
letting process 1 run and finish while process 0 I/O is being also run
in the background. In total it takes 7 times to complete both processes.

4. We’ll now explore some of the other flags. One important flag is
-S, which determines how the system reacts when a process is-
sues an I/O. With the flag set to SWITCH ON END, the system
will NOT switch to another process while one is doing I/O, in-
stead waiting until the process is completely finished. What hap-
pens when you run the following two processes (-l 1:0,4:100
-c -S SWITCH ON END), one doing I/O and the other doing CPU
work?
> It will take 11 times to complete both processes. (correct)

5. Now, run the same processes, but with the switching behavior set
to switch to another process whenever one is WAITING for I/O (-l
1:0,4:100 -c -S SWITCH ON IO). What happens now? Use -c
and -p to confirm that you are right.
> It will take 7 times like it did in the case of the question 3. (correct)

6. One other important behavior is what to do when an I/O com-
pletes. With -I IO RUN LATER, when an I/O completes, the pro-
cess that issued it is not necessarily run right away; rather, what-
ever was running at the time keeps running. What happens when
you run this combination of processes? (./process-run.py -l
3:0,5:100,5:100,5:100 -S SWITCH ON IO -c -p -I
IO RUN LATER) Are system resources being effectively utilized?
> I believe since process 0 is requesting only I/O instructions, when it
initiates and passes control to next processes that use CPU 100% of the time,
while other processes are running, process 0 I/O will finish and it will
wait for all the next processes to finish until it reclaims control. I/O and
CPU are not used effectively. Its later I/O operations are delayed until the
CPU-bound processes finish, so they cannot overlap with their CPU work.

7. Now run the same processes, but with -I IO RUN IMMEDIATE set,
which immediately runs the process that issued the I/O. How does
this behavior differ? Why might running a process that just com-
pleted an I/O again be a good idea?
> With the IO_RUN_IMMEDIATE flag set, resources are used more effectively.
Process 0 starts first I/O and while running it in the background process 1
starts it's CPU instructions, when process 0's I/O completes, process 0
immediately reclaims the CPU, interrupting whichever CPU-bound process is
currently running, marking the first I/O done and starting next I/O. This repeats
until process 0 has issued all of its I/O requests. Its final I/O completion can
interrupt process 3 while process 3 is still executing CPU instructions.

8. Now run with some randomly generated processes using flags -s
1 -l 3:50,3:50 or -s 2 -l 3:50,3:50 or -s 3 -l 3:50,
3:50. See if you can predict how the trace will turn out. What hap-
pens when you use the flag -I IO RUN IMMEDIATE versus that
flag -I IO RUN LATER? What happens when you use the flag -S
SWITCH ON IO versus -S SWITCH ON END?
> SWITCH_ON_IO improves CPU utilization when another process is READY,
because the CPU can work while one process waits for I/O.
IO_RUN_IMMEDIATE differs from IO_RUN_LATER only when an I/O completion
occurs while another process is running. Immediate lets the I/O-bound
process quickly issue its next I/O request; later lets the current
CPU-bound process continue.
