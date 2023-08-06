string justify(const vector<string>& words, int start, int end, int space, bool isLast) {
    string line;
    if (!isLast) {
		int count = end - start - 1;  // number of space slots = number of words - 1
        for (int i = start; i < end; ++i) {
            line += words[i];
            if (count > 0) {
                int cur = space % count != 0? space/count + 1: space/count;
                line.insert(line.end(), cur, ' ');
                space -= cur;
                --count;
            }
        }
    } else {
        for (int i = start; i < end; ++i) {
            line += words[i];
            if (space-- > 0) line.push_back(' ');
        }

    }
    if (space > 0) line.insert(line.end(), space, ' ');
    return line;
}