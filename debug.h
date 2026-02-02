template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

template <typename T>
void dbg_out(const char* name, T&& value) { cerr << name << ": " << value << "\n\n";}

template <typename Head, typename... Tail>
void dbg_out(const char* names, Head&& head, Tail&&... tail) {
    const char* comma = strchr(names, ',');
    cerr.write(names, comma - names) << ": " << head << '\n';
    while (*++comma == ' ');
    dbg_out(comma, tail...);
}

#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__);