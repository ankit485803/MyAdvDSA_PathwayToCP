
/*

Celebrating 100 days of DSA problem-solving on LeetCode! 🚀 

On 23rd Nov 2025 (Sunday - Sem5 IITP 3rd year endSemPaper)
In this video, I reflect on my journey and share how I learned Git LFS (Large File Storage) to manage large files. Git LFS lets you push files up to 5 GB, while GitHub's regular file limit is 50 MB. 
 #LeetCode #DSA #GitLFS




If you want to keep large files in your Git repository, 
consider using Git LFS (Large File Storage), which is designed for handling large files like videos, datasets, etc.
Install Git LFS if you haven't already:



Q. how much the max file size can handle by Git LFS and allowed to push
Ans: Git LFS can handle files up to 5 GB.
GitHub allows 1 GB of storage and 1 GB of bandwidth per month for free-tier accounts, with additional storage 
available for purchase.



Git LFS (Large File Storage) itself does not impose a strict maximum file size limit, but the hosting provider you use for your Git repository will have specific limits for files tracked by LFS.
Common LFS File Size Limits by Hosting Provider:
GitHub:
        GitHub Free and Pro: 2 GB per file
        GitHub Team: 4 GB per file
        GitHub Enterprise Cloud: 5 GB per file
        Azure Repos: 5 GB per file
        Bitbucket Cloud: 5 GB per file
Other Platforms/Self-Hosted Solutions (e.g., GitLab): These may also have similar limits, often around 5 GB per file, 
but can be configured differently depending on the setup.



Que. if i do normal push this also use LFS if not big file video 

If you're pushing files that aren't large or binary (like video files), Git will not use Git LFS by default. 
Git LFS is only triggered for files that match patterns specified in the .gitattributes file or explicitly added to LFS.

How LFS is used:
        Normal Push (without LFS): If the files are regular text-based files (such as .cpp, .py, .txt, etc.), Git handles them as usual. 
        You would just commit and push these files directly into the repository.
        Files Tracked by LFS: If the files are large (like videos, images, or large datasets) and match the LFS patterns in .gitattributes, they will be handled by LFS, even when doing a normal git push.



The -a flag in the git tag command stands for annotated tag. Annotated tags are stored as full objects in the Git database, which means they can contain metadata like the tagger’s name, email, and date, along with a message. 
This is different from lightweight tags, which are just a reference to a commit.        
        

Git uses a parent-child relationship for commits. When you make a new commit, it points to the previous commit (its parent), 
and this forms a linked list of commits in Git’s history.
Commit f7691d4 is the new commit that was just created.
The parent commit 439163a is the commit just before f7691d4.

In Git, commits form a linked chain (a directed acyclic graph or DAG),
 where each commit points back to its parent commit. This forms a history of changes.




 A file with a .h extension is a header file used in C, C++, 
 and Objective-C programming to contain declarations of functions, data types, and macros  (src: https://github.com/amanagr6697/TicTacToeLLD/blob/master/Board.h)


 The time and space values you see in the GitHub repo are related to the performance metrics of the code for each problem, 
 likely provided by a platform like LeetHub (which integrates GitHub with LeetCode solutions). src:  https://github.com/sharmaanuj334/DSA


 
*/




git lfs install
git lfs track "*.mp4"
 git add .gitattributes
git commit -m "Track .mp4 files with Git LFS"
git push origin main


git tag -a v1.7-KandeAlgoForSubarrSum-TeX-markupLang -m "TeX is a typesetting markupLang used by overleaf compiler (relativePath: 01_LeetCode/OverLeaf).  Kandane’s Algorithm efficiently finds the contiguous subarray with the largest sum in linear time.  " 
git push --tags 
git show v1.7-KandeAlgoForSubarrSum-TeX-markupLang




/*

qno 3607  https://leetcode.com/problems/power-grid-maintenance/description/
in this prob concets used Tree DFS BFS




C:\Users\sanja\Desktop\GitProj\MyAdvDSA_PathwayToCP\Chapter_DS\Linear\05_LinkedList\Basic_LL_Concept.cpp
Concepts Clearing Ques for LikedList

qno 876  https://leetcode.com/problems/middle-of-the-linked-list/description/


Note: LL is Linear DS, variableSize, DynamicMemoryAllocation, Non-contigious size 
        ArrayList  v/s  LinkedList 

Insert: TC=O(n)    ...... O(1)     
Search: TC=O(1)    .....  O(n) 

in mostcase apko HEAD of LL given hoga but not tail in the ques 



qno 2095   https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

qno 203  https://leetcode.com/problems/remove-linked-list-elements/description/

qno 206  https://leetcode.com/problems/reverse-linked-list/description/

qno 234  https://leetcode.com/problems/palindrome-linked-list/description/



day2 ka
qno 24  https://leetcode.com/problems/swap-nodes-in-pairs/description/

install gcc  compiler https://sourceforge.net/projects/mingw/


day3
qno  2181  https://leetcode.com/problems/merge-nodes-in-between-zeros/description/

qno 2130  https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/



day4
qno 21  https://leetcode.com/problems/merge-two-sorted-lists/description/



day5

qno 142  https://leetcode.com/problems/linked-list-cycle-ii/description/

qno 3234  https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/description/
qno 2274  https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/description/


day6
qno 2536  https://leetcode.com/problems/increment-submatrices-by-one/description/


7th Jan 2026 (Wednesday - happyNewYr25 and happyBirthdayChhotiSister)
qno 160  https://leetcode.com/problems/intersection-of-two-linked-lists/description/






some matrixProb
qno 2435  https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/




*/