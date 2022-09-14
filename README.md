# xv6-memory-sharing-between-processes
Memory sharing between processes.

Sharing memory between processes, limited to processes that are in a parent-child relationship. The parenting process should report to the operating system the memory that is shared, and all immediate children of that process they can get from the operating system in their address space access to that very memory in the parenting process.

New programs

primestart-
Starts other two programs and create shared variables

primecom-
The primecom user program is tasked with accepting commands from the user in a loop.
Possible commands that the user can enter are:
prime <n> - ispisuje n-ti prost broj
latest - prints the largest prime number found so far
pause - pauses the search for prime numbers
resume - resumes the search for prime numbers
end - tells the primecalc process to shut down
  
primecalc-
The user program primecalc is tasked with searching for prime numbers.
