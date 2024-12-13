char* longestPalindrome(char* s) {
    int len = strlen(s);
    char* s_prime = (char*)malloc(sizeof(char) * (2 * len + 2));
    s_prime[0] = '#';
    int j = 1;
    for (int i = 0; i < len; i++) {
        s_prime[j++] = s[i];
        s_prime[j++] = '#';
    }
    s_prime[j] = '\0';

    int n = strlen(s_prime);
    int* palindrome_radii = (int*)malloc(n * sizeof(int));
    memset(palindrome_radii, 0, n * sizeof(int));
    int center = 0;
    int radius = 0;

    for (int i = 0; i < n; i++) {
        int mirror = 2 * center - i;

        if (i < radius) {
            palindrome_radii[i] = (radius - i > palindrome_radii[mirror]
                                       ? palindrome_radii[mirror]
                                       : radius - i);
        }

        while (i + 1 + palindrome_radii[i] < n &&
               i - 1 - palindrome_radii[i] >= 0 &&
               s_prime[i + 1 + palindrome_radii[i]] ==
                   s_prime[i - 1 - palindrome_radii[i]]) {
            palindrome_radii[i]++;
        }

        if (i + palindrome_radii[i] > radius) {
            center = i;
            radius = i + palindrome_radii[i];
        }
    }

    int max_length = 0;
    int center_index = 0;
    for (int i = 0; i < n; i++) {
        if (palindrome_radii[i] > max_length) {
            max_length = palindrome_radii[i];
            center_index = i;
        }
    }

    int start_index = (center_index - max_length) / 2;
    char* longest_palindrome = (char*)malloc(max_length + 1);
    strncpy(longest_palindrome, &s[start_index], max_length);
    longest_palindrome[max_length] = '\0';

    free(s_prime);
    free(palindrome_radii);

    return longest_palindrome;
}
