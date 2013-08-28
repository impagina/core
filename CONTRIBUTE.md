# How do i contribute?

Contributions to Scribus-core is very easy. Being on GitHub, the source code has become social.

What does that mean?

Very simple: You don't need to ask if you can help, you don't need to apply to join the team - all you do is you fork our repository. In your own fork you can implement and test any enhancements or fixes you would like to contribute. Once you feel your code is ready, just let us know by starting a pull request. The pull request informs the team that there is a new contribution ready to get merged into the main line of code.

Make sure you work in the proper branch. Right now (as of the time of this writing) only have a master, but we will have branches for 0.1, 1.0, 1.5, 1.6 and master.

So fork away and surprise us with great new features, fixes and extensions!


# Create a new branch with git and manage branches

In your github fork, you need to keep your master branch clean, I mean by clean without any changes, like that you can create at any time a branch from your master. Each time, that you want commit a bug or
a feature, you need to create a branch for it, which will be somehow the copy of your master branch. 

When you will do a pull request on a branch, you can continue to work on an another branch and make an another pull request on this other branch. 

Before create a new branch pull the changes from upstream, your master need to be uptodate.

Create the branch on your local machine :

    $ git branch <name_of_your_new_branch>

Push the branch on github :

    $ git push origin <name_of_your_new_branch> 

Switch to your new branch :

    $ git checkout <name_of_your_new_branch>

When you want to commit something in your branch, be sure to be in your branch.

You can see all branches created by using 

<pre>$ git branch </pre>

Which will show :

    * <name_of_your_new_branch>
      master
      master_clean

Add a new remote for your branch :

    $ git remote add <name_of_your_remote> <url>

Push changes from your commit into your branch :

    $ git push origin <name_of_your_remote>

Delete a branch on your local filesytem :

    $ git branch -d <name_of_your_new_branch>

Delete the branch on github :

    $ git push origin :<name_of_your_new_branch>

The only difference it's the `:` to say delete.

If you want to change default branch, it's so easy with github, in your fork go into Admin and in the drop-down list default branch choose what you want.

(Source of inspiration: https://github.com/Kunena/Kunena-Forum/wiki)
