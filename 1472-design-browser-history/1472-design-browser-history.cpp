class BrowserHistory
{
    private:
        stack<string> pre, forw, tmp;
    string curr;

    public:
        BrowserHistory(string homepage)
        {
            curr = homepage;
        }

    void visit(string url)
    {
        pre.push(curr);
        curr = url;
        // when we visit a new url , stack of forward urls become empty
        forw = tmp;
    }

    string back(int steps)
    {
        while (steps > 0 && pre.size() > 0)
        {
            forw.push(curr);
            curr = pre.top();
            pre.pop();
            steps--;
        }
        return curr;
    }

    string forward(int steps)
    {
        while (steps > 0 && forw.size() > 0)
        {
            pre.push(curr);
            curr = forw.top();
            forw.pop();
            steps--;
        }
        return curr;
    }
};

/**
 *Your BrowserHistory object will be instantiated and called as such:
 *BrowserHistory* obj = new BrowserHistory(homepage);
 *obj->visit(url);
 *string param_2 = obj->back(steps);
 *string param_3 = obj->forward(steps);
 */