#include <libmx.h>

// int mx_count_substr(const char *str, const char *sub)
// {
//     if (!str || !sub)
//         return -1;

//     if (mx_strcmp(sub, "") == 0)
//         return 0;

//     unsigned string_length = mx_strlen(str);
//     unsigned sub_length = mx_strlen(sub);

//     if (string_length >= sub_length)
//     {
//         unsigned result = 0;
//         for (bool is_sub; (str = mx_strchr(str, *sub)); str += is_sub ? 1 : sub_length)
//             if ((is_sub = mx_strncmp(str, sub, sub_length)) == 0)
//                 ++result;

//         return (int)result;
//     }
//     return str && sub ? 0 : -1;
// }

void computeLPSArray(const char *sub, int M, int lps[])
{

    // Length of the previous longest
    // prefix suffix
    int len = 0;
    int i = 1;
    lps[0] = 0; // lps[0] is always 0

    // The loop calculates lps[i] for
    // i = 1 to M-1
    while (i < M)
    {
        if (sub[i] == sub[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (sub[i] != sub[len])
        {

            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = lps[len - 1];

                // Also, note that we do not
                // increment i here
            }
            else // if (len == 0)
            {
                lps[i] = len;
                i++;
            }
        }
    }
}

// KMPSearchconst char *str, const char *sub
int mx_count_substr(const char *str, const char *sub)
{

    int M = mx_strlen(sub);
    int N = mx_strlen(str);

    // Create lps[] that will hold the longest
    // prefix suffix values for subtern
    int lps[M];
    int j = 0; // index for sub[]

    // Preprocess the subtern (calculate lps[]
    // array)
    computeLPSArray(sub, M, lps);

    int i = 0; // index for str[]
    int res = 0;
    // int next_i = 0;

    while (i < N)
    {
        if (sub[j] == str[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {

            // When we find subtern first time,
            // we iterate again to check if there
            // exists more subtern
            j = lps[j - 1];
            res++;
        }

        // Mismatch after j matches
        else if (i < N && sub[j] != str[i])
        {

            // Do not match lps[0..lps[j-1]]
            // characters, they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return res;
}
