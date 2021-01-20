# Lab 0: `g++`, `make`, `git`, `docker` (5 pts)

This assignment is to familiarize you with the environment that we will be using for labs/homeworks/projects in the course. It includes the basic usage of `git` (the version control system), `g++` and `make` (the building tools), and `docker` (the virtualization tool for testing). The outcome is a "hello world" program.

The assignment will be delivered to you via Github Classroom.
You should follow the steps below to complete and submit your work.


## Install Docker and Git

The very first step is to install the latest stable version of [Git](https://git-scm.com/downloads) and [Docker](https://docs.docker.com/get-docker/). You will use Git for managing and uploading your code and use Docker for running and testing your code. The actual editing of code will be within your local environment. You could choose whichever operating system (for example, macOS, Windows, Linux) and whatever text editors you like (for example, [Vim](https://www.vim.org/), [Emacs](https://www.gnu.org/software/emacs/), [Visual Studio Code](https://code.visualstudio.com/), [Sublime Text](https://www.sublimetext.com/)). You could also use IDEs, but the final submission should be runnable via Docker as we will use it for autograding.

To verify the installation, open the "Terminal" application ("Powershell" on Windows) and run the following:

```bash
git --version
docker --version
```

If you have any problems regarding the installation, feel free to post on Piazza.

## Github and `git`

An invitation email to Github Classroom and this assignment will be (or has been) sent to your university email.
Before going forward, you should sign up for a [Github](https://github.com/join) account. You could use your personal or university email address. This will not affect your access to the assignments.
After that, go accept the assignment and link your Github account to the classroom roster. This step will allow the instructor to access each individual submission and the results of autograder tests by your Github ID, as well as your name.

You will be directed to your own private repository for the assignment `cisc2200/lab0-YOUR_GITHUB_ID` after accepting the invitation (a.k.a. the remote repository). Now you can clone the repository to local storage (a.k.a. the local repository) and `cd` to the local repository by running the following commands:

```bash
cd SOME_WORKING_DIRECTORY # any directory you'd like to put you code in
git clone https://github.com/cisc2200/lab0-YOUR_GITHUB_ID.git
cd lab0-YOUR_GITHUB_ID
```


## The first C++ program

There are several files and directories in your local copy of the repository, including

- `.git`: configuration for git
- `.github`: scripts to trigger autograder when you commit your code to Github
- `.gitignore`: files that you do not want to track by version control, such as intermediate results
- `Dockerfile`: configuration for Docker
- `hello.cpp`: the file you need to modify
- `Makefile`: configuration for `make`
- `README.md`: this file

You should change the content of `hello.cpp` to print "Hello world!" to the standard output. (Feel free to use any editor.)
The autograder will check the output of the program and give credits only if it &#x1F34E;***exactly matches***&#x1F34F; the string "Hello world!".

<!-- Future assignments will also use this mechanism for grading, by comparing your output with the expected output under specific inputs. -->

Notice: &#x1F34E;**NEVER**&#x1F34F; modify files in `.git` and `.github`.


## Build and run

When your `hello.cpp` is ready, you could run in terminal the following commands to build a Docker container that runs a Linux environment on top of your local OS and inside it compile and execute the program to print the string "Hello world!":

```bash
docker build -t cisc2200 .
docker run -it --rm -v /full/path/to/lab0-YOUR_GITHUB_ID:/lab cisc2200 "make && ./hello.out"
# on Windows, the full path should be like "c:/Users/username/SOME_WORKING_DIRECTORY/lab0-YOUR_GITHUB_ID"
```

I recommend you to take a look at the [g++ and make](https://web.stanford.edu/class/cs193d/handouts/make.pdf) slides and [C++ tutorial](http://www.cplusplus.com/doc/tutorial/introduction/) to get a general idea about the two tools and compilation in general, if you are not familiar with them. More information could be found on their [official](https://gcc.gnu.org/) [websites](https://www.gnu.org/software/make/).
Docker is popular but complex. Understanding its internals is beyond this course. If you are interested, you could refer to Docker's [tutorial](https://docs.docker.com/get-started/).
In future assignments, workable `Makefile`s and `Dockerfile`s will typically be provided. Your focus will be on problem solving by editing C++ code (in `.h` and/or `.cpp` files).


## Commit and submit

After testing the program by running it, you should commit your changes to `hello.cpp` in the local repository and submit them back to the remote repository on Github:

```bash
git add hello.cpp
git commit -m "add: print hello world"
git push
```

You could check the autograder results in the "Actions" tab in the repository website (`https://github.com/cisc2200/lab0-YOUR_GITHUB_ID/actions`).
