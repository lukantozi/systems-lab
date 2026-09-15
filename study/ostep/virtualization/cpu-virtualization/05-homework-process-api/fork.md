# Homework (simulation)

1. Run ./fork.py -s 10 and see which actions are taken. Can you
predict what the process tree looks like at each step? Use the -c
flag to check your answers. Try some different random seeds (-s)
or add more actions (-a) to get the hang of it.
 
 ```
Action: a forks b
        a --
            |
            b

Action: a forks c
      -- a --
     |       |
     c       b

Action: c EXITS
        a --
            |
            b

Action: a forks d
      -- a --
     |       |
     d       b

Action: a forks e
      -- a --
     |   |   |
     d   e   b
```

2. One control the simulator gives you is the fork_percentage, con-
trolled by the -f flag. The higher it is, the more likely the next ac-
tion is a fork; the lower it is, the more likely the action is an exit.
Run the simulator with a large number of actions (e.g., -a 100)
and vary the fork_percentage from 0.1 to 0.9. What do you
think the resulting final process trees will look like as the percent-
age changes? Check your answer with -c.

```
if the percentage is high, tree will be branched out more, and
if it's low, the tree will be shorter
```

3. Now, switch the output by using the -t flag (e.g., run ./fork.py
-t). Given a set of process trees, can you tell which actions were
taken?

```
                               a

a forks b
                               a
                               └── b
a forks c
                               a
                               ├── b
                               └── c
c forks d
                               a
                               ├── b
                               └── c
                                   └── d
a forks e
                               a
                               ├── b
                               ├── c
                               │   └── d
                               └── e
c exits
                               a
                               ├── b
                               ├── e
                               └── d
```

4. One interesting thing to note is what happens when a child exits;
what happens to its children in the process tree? To study this, let’s
create a specific example: ./fork.py -A a+b,b+c,c+d,c+e,c-.
This example has process ’a’ create ’b’, which in turn creates ’c’,
which then creates ’d’ and ’e’. However, then, ’c’ exits. What do
you think the process tree should like after the exit? What if you
use the -R flag? Learn more about what happens to orphaned pro-
cesses on your own to add more context.

```
Such process receives parent that is kernel predefined, usually init.
In our case it's process a. Adding -R flag reparents orphaned processes
to the immediate parent of the terminated process.
```

5. One last flag to explore is the -F flag, which skips intermediate
steps and only asks to fill in the final process tree. Run ./fork.py
-F and see if you can write down the final tree by looking at the
series of actions generated. Use different random seeds to try this a
few times.

```
                           Process Tree:
                               a

Action: a forks b
Action: a forks c
Action: c forks d
Action: a forks e
Action: d EXITS

                        Final Process Tree?
                        a
                        |
                        --- b
                        |
                        --- c
                        |
                        --- e

```

6. Finally, use both -t and -F together. This shows the final process
tree, but then asks you to fill in the actions that took place. By look-
ing at the tree, can you determine the exact actions that took place?
In which cases can you tell? In which can’t you tell? Try some dif-
ferent random seeds to delve into this question.

```
Example 1:
                           Process Tree:
                               a

Action?
Action?
Action?
Action?
Action?

                        Final Process Tree:
                               a
                               └── d

In the example above, I assume the order of actoins were:
a forks b
b forks c
c forks d
b exits
c exits

---

Example 2:
                           Process Tree:
                               a

Action?
Action?
Action?
Action?
Action?

                        Final Process Tree:
                               a
                               ├── b
                               ├── c
                               └── e
a forks b
a forks c
a forks d
d exits
a forks e
---

Final tree does not prove what the exact sequence was.
```
