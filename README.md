# ESP32 Starter Kit for TDD

Setting up a project to use test-first development using the esp-idf toolkit
for esp32 can be challenging.  After doing it the hard way a few times, I sat
down and worked out what the simplest thing would be.  May the sweat of my brow
save the sweat of yours.  And also possibly your bacon.

## Use The Repository

1. Download the project (unless you have serious git skills, this will be easier than cloning it).


1. Create a bare git repository on the git repo provider of your choice (GitHub, GitLab, Bitbucket, etc).

1. Unzip the folder in your workspace.

1. Rename the folder for your project, ideally matching the slug for your remote git repo.

1. Run `git init`

1. Set the remote repository as per the instructions from your git repository, such as 

    git remote add origin git@github.com/MyUserName/super-esp32-project.git

## Get the Test Suite

This repository is set up to use the
[Unity](http://www.throwtheswitch.org/unity) test suite.  Install it as part of
your project by running the script provided in the `unity/` folder.

    ./source-library.sh

If you are running on Windows, you may need to do this with the git-bash shell
that you were prompted to install when you installed git.

## Configuring The TDD Build

First, you need to launch a regular build with the idf.py tool.  This will
create an important config file that is needed for the TDD build.

Now issue the following commands *from the root folder of the project*:

    
    mkdir tdd
    cd tdd
    cmake -DTDD=true -G"Unix Makefiles" ..
    make tdd

You should get a successful build with a failing test.  This proves that the
test suite was correctly installed (yes, I test drove the build).

## Living With Your Project


### Adding New Files

When you add new files, you will need to change to the tdd folder and run the
following command:

    cmake ..

The tdd folder remembers that it is configured for TDD, rather than a regular
build, and will make the right choices.

### Running Tests

I find the simplest way to build and run tests is to keep a terminal open at
all times, and issue the commands

    make tdd

This will trigger a build and automatically run the tests.


### Working With an IDE

I develop most of my C projects using a programming text editor, like vi or VS
Code, and appropriate C plugins.  This project was optimized for that working
style.  If you feel more comfortable with a proper IDE, you will need to figure
out how to configure the way it runs cmake.

The important factor is that the TDD variable is defined for the project.  If
you get weird results from cmake, figure out how to get the `-DTDD=true` flag
passed to cmake in your IDE.

Please note that your IDE's test suite integration won't work with this
project.  Most IDEs will let you set up a default target to run (which should
be test/changeme-test), or a default target to build (which should be tdd).
You'll have to parse the test output yourself, but fortunately unity provides
very nice test messages, and you can always define custom messages for your
assertions if you find that the default messages aren't sufficient.

#### CLion

With CLion, you will need to do the following:

* In the CMake config for your project, add the options

    -DTDD=true -G"Unix Makefiles"

* Choose "changeme-test" as the run target for running tests.

If you are running on windows, if when you try to run cmake you get a message
in the console about not being able to run make if sh.exe is present on the
system, you will need to switch to a system cmake that doesn't throw this
message.  If the message shows up *only* in the toolchain dialog, you can
safely ignore it.  Most modern makes run perfectly fine even if sh.exe is
present on your system.  If you install cmake and make via chocolatey, you
should not have any problems.

#### QtCreator

With QtCreator, you will need to choose "Project" and in the CMake tab, make
sure the box marked TDD is checked.

When you apply settings, the cmake configuration should proceed normally.
After the first build, QtCreator should detect the "changeme-test" target.  You
should select that as the default target.

The Run step should choose "changeme-test" as its default executable.

Following these changes, manually run CMake on the project.  Now when you click
run, you should get a test run.  Note that you will need to look at the test
run output yourself.  It is not displayed by default.
