#include <iostream>
using namespace std;

// Function to calculate the length of a string
int getLength(const char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to get a substring

char* getSubstring(const char str[], int start, int length) {
    // Allocate memory for the substring (+1 for the null terminator)
    char* result = new char[length + 1];

    int i;
    for (i = 0; i < length && str[start + i] != '\0'; i++) {
        result[i] = str[start + i];
    }

    // Null-terminate the result string
    result[i] = '\0';

    return result; // Return the dynamically allocated substring
}


// Function to find the index of a pattern in a string
int getIndex(const char str[], const char pattern[]) {
    int strLen = getLength(str);
    int patLen = getLength(pattern);

    for (int i = 0; i <= strLen - patLen; i++) {
        int j;
        for (j = 0; j < patLen; j++) {
            if (str[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == patLen) {
            return i; // Found the pattern
        }
    }
    return -1; // Pattern not found
}

// Function to concatenate two strings
void concatenateStrings(const char str1[], const char str2[], char result[]) {
    int i = 0, j = 0;

    // Copy str1 to result
    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }

    // Append str2 to result
    while (str2[j] != '\0') {
        result[i++] = str2[j++];
    }
    result[i] = '\0';
}

// Function to insert a substring
char* insertSubstring(const char str[], const char sub[], int position) {
    // Calculate the lengths of the input strings
    int strLength = 0, subLength = 0;
    while (str[strLength] != '\0') strLength++;
    while (sub[subLength] != '\0') subLength++;

    // Allocate memory for the resulting string
    int resultLength = strLength + subLength + 1; // +1 for null terminator
    char* result = new char[resultLength];

    int i = 0, j = 0, k = 0;

    // Copy characters from the original string up to the position
    while (i < position && str[i] != '\0') {
        result[k++] = str[i++];
    }

    // Copy characters from the substring
    while (sub[j] != '\0') {
        result[k++] = sub[j++];
    }

    // Copy the remaining characters from the original string
    while (str[i] != '\0') {
        result[k++] = str[i++];
    }

    // Null-terminate the resulting string
    result[k] = '\0';

    return result; // Return the resulting string
}


// Function to delete a part of the string
#include <iostream>
using namespace std;

char* deleteSubstring(const char str[], int start, int length) {
    int strLength = 0;

    while (str[strLength] != '\0') strLength++;

    int resultLength = strLength - length + 1;
    char* result = new char[resultLength];

    int i = 0, k = 0;

    while (i < start && str[i] != '\0') {
        result[k++] = str[i++];
    }

    i += length;

    while (str[i] != '\0') {
        result[k++] = str[i++];
    }

    result[k] = '\0';

    return result;
}



// Function to replace a pattern in a string
char* replaceSubstring(const char str[], const char pattern[], const char replacement[]) {
    int index = getIndex(str, pattern);

    if (index == -1) {
        int length = getLength(str);
        char* result = new char[length + 1];
        
        int i = 0;
        while (str[i] != '\0') {
            result[i] = str[i];
            i++;
        }
        result[i] = '\0';
        return result;
    }

    int resultLength = getLength(str) - getLength(pattern) + getLength(replacement) + 1;
    char* result = new char[resultLength];

    int i = 0, k = 0;

    while (i < index) {
        result[k++] = str[i++];
    }

    int j = 0;
    while (replacement[j] != '\0') {
        result[k++] = replacement[j++];
    }

    i += getLength(pattern);

    while (str[i] != '\0') {
        result[k++] = str[i++];
    }

    result[k] = '\0';

    return result;
}

int main() {
    char str1[] = "TO BE OR NOT TO BE";
    char str2[] = "XYZ";
    char result[100];

    // Length
    cout << "Length of str1: " << getLength(str1) << endl;

    // Substring
   // getSubstring(str1, 4, 7);
    cout << "Substring of str1 (4, 7): " << getSubstring(str1, 4, 7) << endl;

    // Indexing
    cout << "Index of 'BE' in str1: " << getIndex(str1, "BE") << endl;

    // Concatenation
    concatenateStrings(str1, str2, result);
    cout << "Concatenation of str1 and str2: " << result << endl;

    // Insertion
    // insertSubstring(str1, "INSERTED", 5);
    cout << "Insert 'INSERTED' in str1 at position 5: " << insertSubstring(str1, "INSERTED", 5) << endl;

    // Deletion
    // deleteSubstring(str1, 3, 4);
    cout << "Delete 4 characters from str1 starting at position 3: " << deleteSubstring(str1, 3, 4) << endl;

    // Replacement
    // replaceSubstring(str1, "BE", "XX");
    cout << "Replace 'BE' with 'XX' in str1: " << replaceSubstring(str1, "BE", "XX") << endl;

    return 0;
}
