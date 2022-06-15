# Philosophers or THE Dining philosophers problem which was originally formulated in 1965 by Edsger Dijkstra as a student exam exercise


# Anas TABTI
In this project, you will learn the basics of threading a process. You will see how to create threads and you will discover mutexes
![image](https://user-images.githubusercontent.com/79755743/173885069-93a568de-c149-4e2d-aa58-8944059fc3c2.png)

# My notes  :

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
 ![image](https://user-images.githubusercontent.com/79755743/173887491-83790b7c-0fce-4093-89d0-8d8019b2aa46.png)


### Concurrency means that two or more threads (or traditional processes) can be in the middle of executing code at the same time;
it could be the same code or it could be different code. The threads may or may not actually be executing at the same time, 
but rather in the middle of it (i.e., one started executing, it was interrupted, and the other one started). 
Every multitasking operating system has always had numerous concurrent processes, even though only one can be on the CPU at any given time. 

#### Concurrency is when two or more tasks can start, run, and complete in overlapping time periods. It doesn't necessarily mean they'll ever both be running at the same instant. For example, multitasking on a single-core machine.




### Parallelism means that two or more threads actually run at the same time on different CPUs  . 
On a multiprocessor machine, many different threads can run in parallel. They are, of course, also running concurrently. 

#### Parallelism is when tasks literally run at the same time, e.g., on a multicore processor. (source https://stackoverflow.com/questions/1050222/what-is-the-difference-between-concurrency-and-parallelism)




## Pthreads :


### Support of Multithreading in C 
The C programming language does not have built-in library support for multithreaded programming. Even though C is a general-purpose programming language that is widely used in embedded systems, system programming, and so forth, some vendors have developed libraries that deal with multithreading to achieve parallelism and concurrency. The library to develop portable multithreaded applications is pthread.h; that is, the POSIX thread library. POSIX stands for portable operating system interface. 
 POSIX threads are lightweight and designed to be very easy to implement. 
 The pthread.h library is an external third-party library that helps you effectively do tasks.
## The following are the functions in the pthread.h library that create, manipulate, and exit the threads :
###  • pthread_create 
###  • pthread_join 
### • pthread_self 
###  • pthread_equal 
###  • pthread_exit
###  • pthread_cancel 
###  • pthread_detach


## Pthread_create (int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg))
 creates a new thread with a thread descriptor. A descriptor is an information container of the thread state, execution status, the process that it belongs to, related threads, stack reference information, and thread-specific resource information allocated by the process. This function takes four arguments as parameters. The return type of this function is an integer.
 
##  pthread_join  (    int     pthread_join(pthread_t thread, void **value_ptr);)

This function waits for the termination of another thread. It takes two parameters as arguments and returns the integer type. It returns 0 on successful termination and –1 if any failure occurs.
The following describes the parameter: 
 • thread takes the ID of the thread that is currently waiting for termination 
• thread_return is an argument that points to the exit status of the termination thread, which is a NULL value.
![image](https://user-images.githubusercontent.com/79755743/173887615-eebc5e92-78a1-4a82-9883-30522f0b2dce.png)

##  pthread_detach  (    int  pthread_detach(pthread_t thread);  )

This function detaches a thread in a detached state. It takes a thread descriptor as an argument and returns the integer value as output. The following shows the syntax. 
The following describes the parameter. thread is a descriptor variable that is passed as an ID, which you want to detach it. These functions are the most common functions in multithreading operations.

# Synchronization

Synchronization refers to one of two distinct but related concepts: synchronization of processes, and synchronization of data. Process synchronization refers to the idea that multiple processes are to join up or handshake at a certain point, in order to reach an agreement or commit to a certain sequence of action. Data synchronization refers to the idea of keeping multiple copies of a dataset in coherence with one another, or to maintain data integrity. Process synchronization primitives are commonly used to implement data synchronization.

### Synchronization Issues 
In order to write any kind of concurrent program, you must be able to reliably synchronize the different threads. Failure to do so will result in all sorts of ugly, messy bugs. Without synchronization, two threads will start to change some data at the same time, one will overwrite the other.

 Synchronization is the method of ensuring that multiple threads coordinate their activities so that one thread doesn’t accidently change data that another thread is working on. This is done by providing function calls that can limit the number of threads that can access some data concurrently. In the simplest case (a Mutual Exclusion Lock—a mutex), only one thread at a time can execute a given piece of code. This code presumably alters some global data or does reads or writes to a device.

 Thread synchronization is defined as a mechanism which ensures that two or more concurrent processes or threads do not simultaneously execute some particular program segment known as critical section.
Overhead costs in threaded code include direct effects such as the time it takes to synchronize your threads. Many clever algorithms are available for avoiding synchronization in some cases, but none of them is portable. You’ll have to use some synchronization in just about any threaded code. It is easy to lose performance by using too much synchronization; for example, by separately protecting two variables that are always used together. Protecting each variable separately means you spend a lot more time on synchronization without gaining parallelism.
```diff

- Deadlocks 
A deadlock is , where one thread needs another thread to do something before it proceeds, 
and the other thread needs something from the first. So they both sit there, doing nothing, waiting for each other, forever.
This is a bad thing. A typical deadlock occurs when thread T1 obtains lock M1, and thread T2 obtains lock M2. Then 
thread T1 tries to obtain lock M2, while thread T2 tries for lock M1. Although typically a two-thread kind of problem,
deadlocks can involve dozens of threads in a circle, 
all waiting for one another. They can involve a single thread that tries to obtain the same mutex twice, 
and they can involve a thread
that holds a lock dying while another thread is waiting for it.

```
![image](https://user-images.githubusercontent.com/79755743/173889988-049ad66c-d916-4f97-8eb1-28025e916203.png)

```diff

+ Lock Your Shared Data!

 All shared data must be protected by locks/Mutexes. Failure to do so will result in truly ugly bugs. 

- Mutexes : 

When the lock is set, no other thread can access the locked region of code.

 The mutual exclusion lock is the simplest and most primitive synchronization variable. 
 It provides a single, absolute owner for the section of code (thus a critical section) 
 that it brackets between the calls to pthread_mutex_lock() and pthread_mutex_unlock(). 
 The first thread that locks the mutex gets ownership, and any subsequent attempts to lock it will fail,
 causing the calling thread to go to sleep. When the owner unlocks it, one of the sleepers will be awakened,
 made runnable, and given the chance to obtain ownership. It is possible that some other thread will 
 call pthread_mutex_lock() and get ownership before the newly awakened thread does. This is perfectly correct
 behavior and must not affect the correctness of your 
``` 
# Unix epoch (time): 

Milliseconds : 1000 ms = 1second  ;
A millisecond (ms or msec) is one thousandth of a second and is commonly used in measuring the time to read to or write from a hard disk or a CD-ROM player or to measure packet travel time on the Internet. For comparison, a microsecond (us or Greek letter mu plus s) is one millionth (10-6) of a second.

### The gettimeofday() function :  It is defined in sys/time.h header file.
tv_sec : It is the number of seconds since the epoch.
tv_usec :It is additional microseconds after number of seconds calculation since the epoch. 
the gettimeofday() function to record the current timestamp. This function is passed a pointer to a struct timeval object, which contains two members: tv sec and t usec. These represent the number of elapsed seconds and microseconds since January 1, 1970 (known as the UNIX EPOCH).


## The Unix epoch is 00:00:00 UTC on 1 January 1970 (an arbitrary date).
(Epoch :  (noun) a particular period of time in history or a person's life.)

### Real time 
is measured either from some standard point (calendar time) or from some fixed point,
typically the start, in the life of a process (elapsed or wall clock time). On UNIX systems, 
calendar time is measured in seconds since midnight on the morning of January 1, 1970, Universal Coordinated Time
(usually abbreviated UTC), and coordinated on the base point for time zones defined by the longitudinal line passing
through Greenwich, England. This date, which is close to the birth of the UNIX system, is referred to as the Epoch.


## CITED

#### https://en.wikipedia.org/wiki/Dining_philosophers_problem
####  https://pages.mtu.edu/~shene/NSF-3/e-Book/MUTEX/locks.html
####  http://www.cse.cuhk.edu.hk/~ericlo/teaching/os/lab/9-PThread/Pass.html
####  https://www.youtube.com/watch?v=7ENFeb-J75k&ab_channel=Computerphile
####  https://pages.mtu.edu/~shene/NSF-3/e-Book/MUTEX/TM-example-philos-1.html 
####  https://en.wikipedia.org/wiki/Unix_time
####  https://www.codegrepper.com/code-examples/c/c+get+time+in+milliseconds
####  https://www.epochconverter.com/
####  Multithreaded programming with pthreads (Lewis B., Berg D.J.) (z-lib.org).pdf
####  https://docs.oracle.com/cd/E19205-01/820-0619/geosb/index.html
####  https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&ab_channel=CodeVault
####  https://miniature-wolfberry-eb4.notion.site/ac7edc44b2f14c7a9b227a72aa3c555b?v=1af803759bf54b6088d9210bfdbfa45c
####  Practical System Programming with C - Pragmatic Example Applications in Linux and Unix-Based Operating Systems. (Sri Manikanta Palakollu) (z-lib.org).pdf
####  https://www.thegeekstuff.com/2012/04/terminate-c-thread/
####  Threads Primer A Guide to Multithreaded Programming (Bil Lewis, Daniel J. Berg) (z-lib.org).pdf



