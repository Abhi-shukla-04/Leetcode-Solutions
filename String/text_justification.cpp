class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int lineLength = 0;

            // Greedily pack as many words as possible
            while (j < n &&
                   lineLength + words[j].size() + (j - i) <= maxWidth) {
                lineLength += words[j].size();
                j++;
            }

            int wordCount = j - i;
            int totalSpaces = maxWidth - lineLength;

            string line;

            // Last line OR line with only one word -> left justified
            if (j == n || wordCount == 1) {
                for (int k = i; k < j; k++) {
                    if (k > i)
                        line += ' ';

                    line += words[k];
                }

                // Fill remaining spaces
                line += string(maxWidth - line.size(), ' ');
            }
            else {
                // Number of gaps between words
                int gaps = wordCount - 1;

                // Minimum spaces per gap
                int spacesPerGap = totalSpaces / gaps;

                // Extra spaces go to left gaps
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        int spaces = spacesPerGap;

                        if (k - i < extraSpaces)
                            spaces++;

                        line += string(spaces, ' ');
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};
