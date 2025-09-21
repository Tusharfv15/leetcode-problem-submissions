class MovieRentingSystem {
public:
    unordered_map<int, set<pair<int, int>>> unrented;
    vector<unordered_map<int, int>> shopCost;
    set<vector<int>> rentedReport;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        shopCost.resize(n);
        for (auto& v : entries) {
            shopCost[v[0]][v[1]] = v[2];
            unrented[v[1]].insert({v[2], v[0]});
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        int total = unrented[movie].size();
        int l = min(5, total);
        for (auto& [p, s] : unrented[movie]) {
            res.push_back(s);
            l--;
            if (l == 0)
                break;
        }
        return res;
    }

    void rent(int shop, int movie) {
        int p = shopCost[shop][movie];
        unrented[movie].erase({p, shop});
        rentedReport.insert({p, shop, movie});
    }

    void drop(int shop, int movie) {
        int p = shopCost[shop][movie];
        unrented[movie].insert({p, shop});
        rentedReport.erase({p, shop, movie});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        int total = rentedReport.size();
        int l = min(5, total);
        for (auto& v : rentedReport) {
            res.push_back({v[1], v[2]});
            l--;
            if (l == 0)
                break;
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */