# Simple Command-Line To-Do List Manager
#### Video Demo:  <URL https://www.youtube.com/watch?v=GqahS_8l0XQ>
#### Description:

Introduction:
The Simple Command-Line To-Do List Manager is a small-scale project implemented in C that allows users to create and manage a to-do list from the command-line interface. The program provides a simple and efficient way to add tasks, mark tasks as completed, list all tasks, and exit the program. It is designed to provide a straightforward and convenient solution for individuals who prefer a command-line interface for managing their tasks.

Features:
1. Add Task:
   Users can add tasks to the to-do list by entering the "add" command followed by the task description. The program validates the input and adds the task to the list, associating it with a unique task ID. If the task list is already full (maximum capacity defined as `MAX_TASKS`), an appropriate error message is displayed.

2. Complete Task:
   Users can mark a task as completed by entering the "complete" command followed by the task index. The program verifies the index and checks if the task is already completed. If the input is valid, the program updates the completion status of the task and displays a success message. In case of an invalid index or attempting to complete an already completed task, the program provides appropriate error messages.

3. List Tasks:
   The "list" command displays all the tasks in the to-do list. Each task is presented with its corresponding task index, completion status, and description. If the task list is empty, a message indicating the absence of tasks is shown.

4. Exit Program:
   Users can exit the program by entering the "exit" command. Upon receiving this command, the program terminates and displays an exit message.

User Interaction:
The project's user interaction is based on a simple command-line interface. Users input commands and parameters through the terminal, and the program responds accordingly. The program utilizes the `fgets` function to capture user input and various string comparison techniques to identify the desired command.

Implementation:
The program is implemented using C programming language. It utilizes arrays and structures to store and manage the tasks. The `struct Task` structure represents an individual task, consisting of a description and a completion status. The tasks are stored in the `taskList` array, which has a maximum capacity defined as `MAX_TASKS`. The `numTasks` variable keeps track of the current number of tasks in the list.

The main function controls the program flow. It repeatedly prompts the user for a command, reads the input, and performs the corresponding operations based on the command. The program uses a while loop to continue accepting commands until the user chooses to exit.

Extensibility:
The project can be extended in various ways to enhance functionality. Some potential improvements include:

1. Task Modification:
   Implement the ability to modify task descriptions or completion status.

2. Task Deletion:
   Allow users to delete tasks from the to-do list.

3. Task Priority:
   Introduce a priority system for tasks, allowing users to assign different levels of importance to tasks.

4. File Persistence:
   Add file I/O operations to store tasks in a file, enabling persistence between program runs.

5. Task Filtering and Sorting:
   Implement features to filter tasks based on completion status, sort tasks by different criteria, or search for specific tasks.

Conclusion:
The Simple Command-Line To-Do List Manager is a basic yet functional project that provides a command-line interface for managing tasks efficiently. With its simple implementation and intuitive user interaction, it offers a convenient solution for individuals who prefer using the command line for task management. The project's extensibility allows for further enhancements and customization to meet specific user requirements.