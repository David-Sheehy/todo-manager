A relatively simple todo list manager.

The default file it manages is a file called "todo.txt" held in the user's
home directory.


Options:

-f or --file [filepath]  

    Uses the filepath argument as the file being managed.  


Commands:  

add  [Task title] [items]

    Adds a new task with the given title to the end of the list of tasks. Any
tokens beyond the intitial titel are interepreted as items. The items are
optional.


amend [n]

    modifies a given task. This is still being designed and should be considered
to be extremely beta function.

demote [n count]

    Reduces the priority of a given task by count. The tasks between the
initial position and final position are promoted by 1.

help

    displays a brief overview of the commands.

list [] [n] [n m]

    Lists either all the tasks recognized by the manager, the nth task or a
range of tasks with priorities from n to m.


promote [n count]

    Increases the priority of a given task by count. The tasks between the
initial position and final position are demoted by 1.

remove [n]

    Removes the nth task from the list.

swap [n m]

    Switches the priority of task n and task m. No other tasks are modified.
