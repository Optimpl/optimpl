namespace optimpl {
    int len(optimpl::str);
}
int optimpl::len(optimpl::str target) {
    return target.__len__();
}