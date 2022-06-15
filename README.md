# Philosophers
In this project, you will learn the basics of threading a process. You will see how to create threads and you will discover mutexes
![image](https://user-images.githubusercontent.com/79755743/173885069-93a568de-c149-4e2d-aa58-8944059fc3c2.png)

# My notes :

## What is a process ?

- Process means a program is in execution, whereas thread means a segment of a process.
 	A program can do nothing unless its instructions are executed by a CPU. A program in execution, as mentioned, is a process.

## What does it need ?
A process needs certain resources—including CPU time, memory, files, and I/O devices— to accomplish its task. 

## What is a Thread ?

Threads In Linux, some processes are divided into pieces called threads. 
A thread is very similar to a process—it has an identifier (TID, or thread ID), and the kernel schedules and runs threads just like processes. 
However, unlike separate processes, which usually do not share system resources such as memory and I/O connections with other processes, 
all threads inside a single process share their system resources and some memory
Each thread has a thread ID (TID), which may be used to control certain aspects (scheduling classes, cancellation, signals, etc.) of that thread. 
(Win32 defines both a TID and a handle, both of which uniquely identify a thread. The TID is defined inside the process, the handle across all processes. 
Some functions use the TID, others the handle.) POSIX TIDs are of type pthread_t, which is an opaque datatype and should not be confused with any other 
datatype
### Let’s consider a human analogy: a bank. A bank with one person working in it (traditional process) has lots of “bank stuff” such as desks and chairs,
a vault, and teller stations (process tables and variables). There are lots of services that a bank provides: checking accounts, loans, savings accounts,
etc. (the functions). With one person to do all the work, that person would have to know how to do everything, and could do so, but it might take a bit of 
extra time to switch among the various tasks. With two or more people (threads), they would share all the same “bank stuff,” 
but they could specialize in their different functions. And if they all came in and worked on the same day, lots of customers could get serviced quickly. 
To change the number of banks in town would be a big effort (creating new processes), but to hire one new employee (creating a new thread) would be very 
simple.
 Everything that happened inside the bank, including interactions among the employees there, would be fairly simple (user space operations among threads),
 whereas anything that involved the bank down the road would be much more involved (kernel space operations between processes). 
All threads within a process share the same address space, and there’s no protection boundary between the threads.
If a thread writes to memory through an uninitialized pointer, it can wipe out another thread’s stack,
or heap memory being used by some other thread. 

### Like us, threads usually can’t stay awake their entire life. Most threads occasionally go to sleep. A thread can go to sleep because it needs a resource that is not available (it becomes “blocked”) or because the system reassigned the processor on which it was running (it is “preempted”). A thread spends most of its active life in three states: ready, running, and blocked.
A thread becomes blocked when it attempts to lock a mutex that is currently locked.
When a thread is unblocked after a wait for some event, it is made ready again. It may execute immediately,
## Viewing Threads 
 $ ps m
 To show all processes use    ps -e          (source https://git.ir/lynda-linux-shells-and-processes/)
 
 # Concurrency vs. Parallelism 

### Concurrency means that two or more threads (or traditional processes) can be in the middle of executing code at the same time;
it could be the same code or it could be different code. The threads may or may not actually be executing at the same time, 
but rather in the middle of it (i.e., one started executing, it was interrupted, and the other one started). 
Every multitasking operating system has always had numerous concurrent processes, even though only one can be on the CPU at any given time. 

#### Concurrency is when two or more tasks can start, run, and complete in overlapping time periods. It doesn't necessarily mean they'll ever both be running at the same instant. For example, multitasking on a single-core machine.




### Parallelism means that two or more threads actually run at the same time on different CPUs  . 
On a multiprocessor machine, many different threads can run in parallel. They are, of course, also running concurrently. 

#### Parallelism is when tasks literally run at the same time, e.g., on a multicore processor. (source https://stackoverflow.com/questions/1050222/what-is-the-difference-between-concurrency-and-parallelism)
