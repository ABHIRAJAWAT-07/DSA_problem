class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0, a = 0, l = 0, o = 0, n = 0;

        for (char c : text) {
            if (c == 'b') b++;
            else if (c == 'a') a++;
            else if (c == 'l') l++;
            else if (c == 'o') o++;
            else if (c == 'n') n++;
        }

        l /= 2;  // "balloon" needs 2 l's
        o /= 2;  // "balloon" needs 2 o's

        return min({b, a, l, o, n});
    }
};