# Operating Systems: Three Easy Pieces - Index

Official index: <https://pages.cs.wisc.edu/~remzi/OSTEP/>

## Intro

[Dedication](https://pages.cs.wisc.edu/~remzi/OSTEP/dedication.pdf)  
[Preface](https://pages.cs.wisc.edu/~remzi/OSTEP/preface.pdf)  
[Table of contents](https://pages.cs.wisc.edu/~remzi/OSTEP/toc.pdf)  
[1. A Dialogue on the Book](https://pages.cs.wisc.edu/~remzi/OSTEP/dialogue-threeeasy.pdf)  
[2. Introduction to Operating Systems](https://pages.cs.wisc.edu/~remzi/OSTEP/intro.pdf) · [code](https://github.com/remzi-arpacidusseau/ostep-code/tree/master/intro)

## I. Virtualization

### CPU virtualization

[3. A Dialogue on Virtualization](https://pages.cs.wisc.edu/~remzi/OSTEP/dialogue-virtualization.pdf)  
[4. The Abstraction: The Process](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-intro.pdf)  
[5. Interlude: Process API](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-api.pdf) · [code](https://github.com/remzi-arpacidusseau/ostep-code/tree/master/cpu-api)  
[6. Mechanism: Limited Direct Execution](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-mechanisms.pdf)  
[7. Scheduling: Introduction](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-sched.pdf)  
[8. Scheduling: The Multi-Level Feedback Queue](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-sched-mlfq.pdf)  
[9. Scheduling: Proportional Share](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-sched-lottery.pdf) · [code](https://github.com/remzi-arpacidusseau/ostep-code/tree/master/cpu-sched-lottery)  
[10. Multiprocessor Scheduling](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-sched-multi.pdf)  
[11. Summary Dialogue on CPU Virtualization](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-dialogue.pdf)

### Memory virtualization

[12. A Dialogue on Memory Virtualization](https://pages.cs.wisc.edu/~remzi/OSTEP/dialogue-vm.pdf)  
[13. The Abstraction: Address Spaces](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-intro.pdf) · [code](https://github.com/remzi-arpacidusseau/ostep-code/tree/master/vm-intro)  
[14. Interlude: Memory API](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-api.pdf)  
[15. Mechanism: Address Translation](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-mechanism.pdf)  
[16. Segmentation](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-segmentation.pdf)  
[17. Free-Space Management](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-freespace.pdf)  
[18. Paging: Introduction](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-paging.pdf)  
[19. Paging: Faster Translations (TLBs)](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-tlbs.pdf)  
[20. Paging: Smaller Tables](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-smalltables.pdf)  
[21. Beyond Physical Memory: Mechanisms](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-beyondphys.pdf)  
[22. Beyond Physical Memory: Policies](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-beyondphys-policy.pdf)  
[23. A Complete Virtual Memory System](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-complete.pdf)  
[24. Summary Dialogue on Memory Virtualization](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-dialogue.pdf)

## II. Concurrency

[25. A Dialogue on Concurrency](https://pages.cs.wisc.edu/~remzi/OSTEP/dialogue-concurrency.pdf)  
[26. Concurrency: An Introduction](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-intro.pdf) · [code](https://github.com/remzi-arpacidusseau/ostep-code/tree/master/threads-intro)  
[27. Interlude: Thread API](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-api.pdf) · [code](https://github.com/remzi-arpacidusseau/ostep-code/tree/master/threads-api)  
[28. Locks](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-locks.pdf) · [code](https://github.com/remzi-arpacidusseau/ostep-code/tree/master/threads-locks)  
[29. Lock-based Concurrent Data Structures](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-locks-usage.pdf)  
[30. Condition Variables](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-cv.pdf) · [code](https://github.com/remzi-arpacidusseau/ostep-code/tree/master/threads-cv)  
[31. Semaphores](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-sema.pdf) · [code](https://github.com/remzi-arpacidusseau/ostep-code/tree/master/threads-sema)  
[32. Common Concurrency Problems](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-bugs.pdf)  
[33. Event-based Concurrency](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-events.pdf)  
[34. Summary Dialogue on Concurrency](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-dialogue.pdf)

## III. Persistence

[35. A Dialogue on Persistence](https://pages.cs.wisc.edu/~remzi/OSTEP/dialogue-persistence.pdf)  
[36. I/O Devices](https://pages.cs.wisc.edu/~remzi/OSTEP/file-devices.pdf)  
[37. Hard Disk Drives](https://pages.cs.wisc.edu/~remzi/OSTEP/file-disks.pdf)  
[38. Redundant Arrays of Inexpensive Disks (RAIDs)](https://pages.cs.wisc.edu/~remzi/OSTEP/file-raid.pdf)  
[39. Interlude: Files and Directories](https://pages.cs.wisc.edu/~remzi/OSTEP/file-intro.pdf)  
[40. File System Implementation](https://pages.cs.wisc.edu/~remzi/OSTEP/file-implementation.pdf)  
[41. Locality and The Fast File System](https://pages.cs.wisc.edu/~remzi/OSTEP/file-ffs.pdf)  
[42. Crash Consistency: FSCK and Journaling](https://pages.cs.wisc.edu/~remzi/OSTEP/file-journaling.pdf)  
[43. Log-structured File Systems](https://pages.cs.wisc.edu/~remzi/OSTEP/file-lfs.pdf)  
[44. Flash-based SSDs](https://pages.cs.wisc.edu/~remzi/OSTEP/file-ssd.pdf)  
[45. Data Integrity and Protection](https://pages.cs.wisc.edu/~remzi/OSTEP/file-integrity.pdf)  
[46. Summary Dialogue on Persistence](https://pages.cs.wisc.edu/~remzi/OSTEP/file-dialogue.pdf)  
[47. A Dialogue on Distribution](https://pages.cs.wisc.edu/~remzi/OSTEP/dialogue-distribution.pdf)  
[48. Distributed Systems](https://pages.cs.wisc.edu/~remzi/OSTEP/dist-intro.pdf)  
[49. Sun's Network File System (NFS)](https://pages.cs.wisc.edu/~remzi/OSTEP/dist-nfs.pdf)  
[50. The Andrew File System (AFS)](https://pages.cs.wisc.edu/~remzi/OSTEP/dist-afs.pdf)  
[51. Summary Dialogue on Distribution](https://pages.cs.wisc.edu/~remzi/OSTEP/dist-dialogue.pdf)

## IV. Security

[52. A Dialogue on Security](https://pages.cs.wisc.edu/~remzi/OSTEP/dialogue-security.pdf)  
[53. Introduction to Operating System Security](https://pages.cs.wisc.edu/~remzi/OSTEP/security-intro.pdf)  
[54. Authentication](https://pages.cs.wisc.edu/~remzi/OSTEP/security-authentication.pdf)  
[55. Access Control](https://pages.cs.wisc.edu/~remzi/OSTEP/security-access.pdf)  
[56. Protecting Information With Cryptography](https://pages.cs.wisc.edu/~remzi/OSTEP/security-crypto.pdf)  
[57. Distributed System Security](https://pages.cs.wisc.edu/~remzi/OSTEP/security-distributed.pdf)

## Appendices and labs

[A Dialogue on Virtual Machine Monitors](https://pages.cs.wisc.edu/~remzi/OSTEP/dialogue-vmm.pdf)  
[Virtual Machine Monitors](https://pages.cs.wisc.edu/~remzi/OSTEP/vmm-intro.pdf)  
[A Dialogue on Monitors](https://pages.cs.wisc.edu/~remzi/OSTEP/dialogue-monitors.pdf)  
[Monitors](https://pages.cs.wisc.edu/~remzi/OSTEP/threads-monitors.pdf)  
[A Dialogue on Labs](https://pages.cs.wisc.edu/~remzi/OSTEP/dialogue-labs.pdf)  
[Laboratory: Tutorial](https://pages.cs.wisc.edu/~remzi/OSTEP/lab-tutorial.pdf)  
[Laboratory: Systems Projects](https://pages.cs.wisc.edu/~remzi/OSTEP/lab-projects-systems.pdf)  
[Laboratory: xv6 Projects](https://pages.cs.wisc.edu/~remzi/OSTEP/lab-projects-xv6.pdf)
