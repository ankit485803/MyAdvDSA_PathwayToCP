// Problem: Check whether a string/sentence is a palindrome,
// ignoring non-alphanumeric characters and case.

// Approach 1: Two Pointers
// Concepts: Two Pointers, String, Character Handling
// TC: O(n), SC: O(1)

bool isPalindrome(const string& s) {
    int left = 0, right = s.length() - 1;

    while (left < right) {
        if (!isalnum(s[left]))
            left++;
        else if (!isalnum(s[right]))
            right--;
        else if (tolower(s[left]) == tolower(s[right]))
            left++, right--;
        else
            return false;
    }

    return true;
}


// Approach 2: Filter + Reverse
// Concepts: String, Character Handling, Reverse
// TC: O(n), SC: O(n)

bool isPalindrome(string s) {
    string filtered;

    for (char ch : s) {
        if (isalnum(ch))
            filtered.push_back(tolower(ch));
    }

    string rev = filtered;
    reverse(rev.begin(), rev.end());

    return filtered == rev;
}