/*

How to create a folder (works in mobile too)
Method (what you should do):
    Open your repo (like your link)
    Tap Add file / + icon
    Tap Create new file
    In filename field, type like this:
                folderName/file.cpp

https://en.wikipedia.org/wiki/Termux
Termux is an Android terminal emulator and Linux environment app that brings powerful command-line utilities to mobile devices. It allows users to run a full Linux distribution on Android without 
rooting, providing access to development tools, scripting languages, and package management


Running as a user-space application, Termux leverages Android’s Linux kernel to provide a native POSIX environment. 
Packages are cross-compiled for ARM and x86 architectures, ensuring compatibility across devices. Data resides in the app’s internal storage, preserving system security and avoiding the need for root privileges.

Termux is a free, open-source terminal emulator and Linux environment application for Android. 
It allows you to run a Linux-style command-line interface on your phone or tablet without needing to "root" the device.

The Android Native Development Kit (NDK) provides a cross-compiling tool for compiling code written in C/C++ can be compiled to ARM, or x86 native code for Android. 
The NDK uses the Clang compiler to compile C/C++. GCC was included until NDK r17, but removed in r18 in 2018.

*/



#include <bits/stdc++.h>
using namespace std;

int findLowerBound(vector<int>& arr, int target) {
    int index = lower_bound(arr.begin(), arr.end(), target) - arr.begin();

    if (index == arr.size()) {
        return -1; // no element >= target
    }

    return index;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 3, 4};
    int target = 2;

    int index = findLowerBound(arr, target);

    if (index != -1 && arr[index] == target) {
        cout << "First occurrence index: " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}