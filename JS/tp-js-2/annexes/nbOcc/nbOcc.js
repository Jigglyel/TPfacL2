function nbOcc(s,ss) {
    index=s.search(ss);
    count=0;
    while (index!=-1) {
        s=s.substring(index+ss.length);
        count++;
        index=s.search(ss);
    }
    return count;
}