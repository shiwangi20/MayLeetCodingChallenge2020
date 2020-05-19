
// Created on : 19 May, 2020

// Title : Online Stock Span

// Author : Shiwangi Garg

class StockSpanner {
public:
    stack<pair<int,int>> stock;
    StockSpanner() {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
    
    int next(int price) {
        int span = 1;
        while(!stock.empty() && price >= stock.top().first){
            span += stock.top().second;
            stock.pop();
        }
        stock.push(make_pair(price,span));
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
