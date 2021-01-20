# Homework 1: Manipulating Arrays (5 pts)

In this homework, you are given one specific implementation of a wrapper around C++'s builtin array as class `Array`. You will complete a method in this `Array` class to *reverse* its internal C++ array. There are **30** test cases (in `tests_rev`) that will be run against your implementation by the autograder. Each test case worths **0.1** pts. You have to pass all 30 tests to get all **3** points.

The second part of the homework is to complete a function that computes the *running sum* of an array (definition given shortly). There are **20** cases for autograding (in `tests_rsum`). You will get **2** pts if your program passes all tests.
The instructor will manually look at your code to evaluate your implementation and give feedback, if you didn't pass the tests. Your final score will depend on your code revision.

## Clone repository to local storage

```bash
cd SOME_DIRECTORY # any arbitrary directory you'd like to store the code
git clone https://github.com/cisc2200/hw1-YOUR_GITHUB_ID.git
cd hw1-YOUR_GITHUB_ID
```

Note that `YOUR_GITHUB_ID` in the above commands should be replaced with your actual ID for GitHub. For example, mine is `zhhailon`. So the commands should be `git clone https://github.com/cisc2200/hw1-zhhailon.git` and `cd hw1-zhhailon`.

The major files/directories in the repository are

- `Array.h`: definition of the `Array` class
- `main_rev.cpp`: test driver for the reverse function
- `main_rsum.cpp`: test driver for the running sum function
- `tests_rev`: test cases for the reverse function; 30 in total, 0.1 pts each (&#x1F34E;**DO NOT MODIFY**&#x1F34F;)
- `tests_rsum`: test cases for the running sum function; 20 in total (&#x1F34E;**DO NOT MODIFY**&#x1F34F;)

## Reversing an array

Below is the main structure of the program in `main_rev.cpp`:

```cpp
// read integers into an Array object `nums`
...

nums.reverse(); // TO BE IMPLEMENTED BY STUDENTS

// print `nums`
...
```

The program reads from standard input (`std::cin`) a series of integers to an `Array` object `nums`. The format of input is: 1) the 1st integer indicates the size of the array, and 2) the following integers are elements of the array. The reading of an array is already provided in the `main` function and you should **not** modify it. If you find any bugs in the code, please let me know. Extra credits will be rewarded.

Next, the array `nums` is reversed by calling `nums.reverse()`. You should complete this function, which is defined in [Array.h](Array.h#L36).
For example, suppose `nums = [1,10,2,1,3]`. The reverse of `nums` is `[3,1,2,10,1]`. The reverse operation should be **in-place** --- that is, do not create a new array for storage, but simple temporary variables are allowed.

Lastly, the program will print the reversed array to `std::cout`, the standard output. The printing is also provided in the `main` function and you should **not** modify it. The output will be used for autograding.

## Running sum of an array

The main structure of the program in `main_rsum.cpp` is as follows:

```cpp
// read integers into an Array object `nums`
...

nums.reverse(); // IMPLEMENTED IN THE FIRST PART
... = runningSum(nums); // TO BE IMPLEMENTED BY STUDENTS

// print running sum
...
```

You should complete function `runningSum` in [main_rsum.cpp](main_rsum.cpp#L5) to compute the running sum of the reversed array `nums`, where the reverse operation has already been implemented in the first part of this homework.

The running sums of an array `nums` is defined as `runningSum[i] = sum(nums[0] ... nums[i])`. For example, the running sum of `nums = [1,2,3,4]` is `[1,3,6,10]`, obtained as follows: `[1, 1+2, 1+2+3, 1+2+3+4]`. As another simple example, the running sum for `nums = [1,1,1,1,1]` is `[1,2,3,4,5]`, obtained as follows: `[1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1]`. The running sum of `nums = [3,1,2,10,1]` is `[3,4,6,16,17]`.

## Testing

### Reversing an array

To compile and run test cases in Docker, you could run the following commands:

```bash
docker build -t hw1 . # build Docker image with tag `hw1`
docker run -it --rm -v /FULL/PATH/TO/hw1-YOUR_GITHUB_ID:/lab hw1 "make rev" # compile the code in Docker
docker run -it --rm -v /FULL/PATH/TO/hw1-YOUR_GITHUB_ID:/lab hw1 "./main_rev.out" # run main_rev.out in Docker
```

In MacOS or Linux, you could use the `pwd` command to get the full path of present working directory (for example, `/Users/zhhailon/cisc2200/hw1-zhhailon`) and replace the `/FULL/PATH/TO/hw1-YOUR_GITHUB_ID` part in the commands above with the result of `pwd`.
On Windows, the full path should be like `c:/Users/username/cisc2200/hw1-YOUR_GITHUB_ID`. This argument maps the current working directory on your local operating system (MacOS, Linux, or Windows) to the directory `/lab` in the Docker system (which in our case is Linux) that will be launched by running `docker run`, so that any modifications of the directory in Docker (for example, generating `main_rev.out` by running `make rev`) become persistent.

Then you could enter your own test cases to test the code. For example, say you would like to use `nums = [1,2,3,4]` for testing. After running the last `docker run ...` command from above, you should type `4 1 2 3 4` then hit enter. The first `4` indicates the number of elements in `nums`, while the remaining integers are the values of those elements.
The output of your program should be `4 3 2 1`, which is the reverse of `1 2 3 4`.
As another example, to test with `nums=[3,1,2,10,1]`, we should enter `5 3 1 2 10 1` and the correct output is `1 10 2 1 3`.


### Running sum of an array

Similarly, run the following commands to test your implementation of the running sum function:

```bash
docker build -t hw1 . # build Docker image
docker run -it --rm -v /FULL/PATH/TO/hw1-YOUR_GITHUB_ID:/lab hw1 "make rsum" # compile the code in Docker
docker run -it --rm -v /FULL/PATH/TO/hw1-YOUR_GITHUB_ID:/lab hw1 "./main_rsum.out" # run main_rsum in Docker
```

Then type in your test cases. For example, for input `5 1 10 2 1 3`, which means that `nums = [1,10,2,1,3]`, the output of the program should be `3 4 6 16 17`, obtained as `3 3+1 3+1+2 3+1+2+10 3+1+2+10+1` --- that is the running sum of the reverse of `nums`.

## Commit and submit

After testing the program, you should commit your changes in the local repository and push them back to the remote repository on GitHub:

```bash
git add Array.h main_rsum.cpp
git commit -m "add Array.reverse and runningSum"
git push
```

You could check the autograder results in the "Actions" tab in the repository webpage.
