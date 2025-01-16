# Welcome

Welcome to CS 24!  This assignment will make sure you have  Git set up correctly
and are ready to submit your programming projects to Gradescope.

If you're new to Git,  here are the important terms you'll need to know for this
assignment:

- A **respository**  (or **repo** for short)  is a folder that's managed by Git.
  All the files in a repo can have their history tracked once they're committed.
- A **commit** is a snapshot of a repository.
- A **branch** is a Git timeline: a series of commits that follow one another.
- When you **merge** a branch into your current branch,  you get all the changes
  (and files) form the other branch added to your current branch.
- A **remote** is a copy of a repository  that lives somewhere else.  Your local
  repo will have two remotes, both of which live on GitHub: you can pull changes
  from the class GitHub repo, and push changes to your personal GitHub repo.


## Git Repo Setup

This class  will use a  single Git repo  for the whole quarter.  Each assignment
will get its own folder within  that repo.  You'll create  a private copy of the
main class repo;  I'll push code to the class repo  as assignments are released,
and you can pull to get the code.

Normally you'd "fork" the class repo on GitHub, but GitHub doesn't allow private
forks of public repos, so this'll be a little more complicated.

First, set up your GitHub account and create a new empty repo:

- Create a GitHub account if you don't already have one.
- Add your SSH key to your GitHub account if it's not there already:
  - Check to see if you have an [existing SSH key][ssh-exists] on your computer.
  - If you don't already have an SSH key, [create one][ssh-create].
  - [Add your SSH key][ssh-github] to your GitHub account.
  - If you have to choose between adding an Authentication Key and a Signing
    Key, choose Authentication Key.
- Create a new repo on GitHub.
  - GitHub will offer to initialize it with some files.  Don't do this!
  - Make sure your new repo is a private repo.

Then download the class repo onto your local machine and configure it to talk to
both GitHub repos:

- [Install and configure Git][git-setup] if you don't have it already.
- Clone the class repo somewhere on your local machine.
- The class repo will be at a remote named `origin`; rename it to `upstream`.
- Add a new remote for your GitHub repo; call it `origin`.  Use the SSH URL.
- Push your local `master` branch to your GitHub repo (the `-u` option, also
  known as `--set-upstream`, will link your local branch to the remote branch):\
  `git push -u origin master`
- Your files should now be visible in the GitHub web UI.

Then check that you have everything set up correctly:

- Make sure the output of `git remote -v` makes sense.
- Save the output of `git remote -v` as `labs/welcome/remotes.txt`.
- Add and commit this file to your local Git repo.
- Push your changes to GitHub.  You linked your local `master` branch to the
  `master` branch on GitHub in the previous section, so now you can simply use:\
  `git push`


## Git Branches

Now that your Git repo is set up, get some practice merging:

- The class repo contains three extra branches:
  - `bart`
  - `fishwife`
  - `jabberwocky`
- Merge all of these into your `master` branch.
  - Git may make you select a "merge strategy."
    If it does, set `pull.rebase` to `false`.
- Push your changes to GitHub.


## Some Code

Now that you have Git set up, it's time to write some code.

First, create the folder `labs/welcome/code`. Then, inside that folder, create a
file named `caprot.cpp`. In this file, write a program that takes one integer as
a  command line argument,  then reads one line from the console.  It should then
print the line with the capitalization right-rotated by the number of characters
given  on the command line  (note that the rotation wraps around when it reaches
the end of the line):

```
[user@host code]$ ./caprot 2
abC123Def
abc123deF
[user@host code]$ ./caprot 5
AbcdEfghIjklmnOpqrstUvwxYz
abcDeFghiJklmNopqrsTuvwxyZ
[user@host code]$ ./caprot -2
HIJ456klm
Hij456kLM
[user@host code]$ ./caprot -108
AbcdEfghIjklmnOpqrstUvwxYz
AbcdEfghijKlmnopQrstUvWxyz
```

If your program is given an incorrect number of command line arguments, print an
error message  to the standard error stream  (`std::cerr`)  and exit immediately
with exit code 1:

```
[user@host code]$ ./caprot 1 2 3 4 5
USAGE: caprot [rotation]
```


## A Makefile

Next, create a `Makefile` inside your `labs/welcome/code` folder. If you haven't
used Makefiles before, see [this tutorial][makefiles] for more information. Your
Makefile should support the following commands:

- Running `make` in that folder should compile `caprot.cpp` to an executable named `caprot`.
- Running `make clean` in that folder should remove the executable and any object files.
- Running `make clean` should succeed even if there is no executable.


## Commit and Submit

If everything looks good, you're ready to submit your code.

- Commit all your changes and push them to GitHub.
- Submit your GitHub repo to Gradescope.
  - You'll be asked to connect your GitHub account to Gradescope if you haven't already.
- Make sure all the tests pass.


## Git Hints

- A Git cheatsheet that may prove helpful:\
  https://xavierholt.github.io/cheatsheets/git.html
- It's always a good idea to run `git status` and see what state your repo is in.
- Git will open a text editor when you make a merge commit, just in case you
  want to edit the automatically generated commit message.  This will probably
  be Vim, so type `:wq` and hit Enter to accept the message and continue.


## Code Hints

- The [cctype][cctype] header contains functions for working with characters,
  but beware!  The `iswhatever()` functions don't return `bool`s; they return
  non-zero for true and zero for false.
- Some of the tests use _very_ large integers.  Watch out for integer overflow!
- If your program is given exactly one command line argument, that argument
  will always be a valid integer.  You don't need to check this.
- Your code should always print exactly one newline, regardless of the input.
- Your code must compile with no warnings (see the syllabus).
- Don't check executables or object files into Git.


[github]: https://github.com
[git-setup]: https://help.github.com/en/github/getting-started-with-github/set-up-git
[makefiles]: https://makefiletutorial.com/
[ssh-exists]: https://docs.github.com/en/authentication/connecting-to-github-with-ssh/checking-for-existing-ssh-keys
[ssh-create]: https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent
[ssh-github]: https://docs.github.com/en/authentication/connecting-to-github-with-ssh/adding-a-new-ssh-key-to-your-github-account
[cctype]: https://cplusplus.com/reference/cctype/
