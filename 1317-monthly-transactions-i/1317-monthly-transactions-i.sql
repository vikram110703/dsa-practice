SELECT 
    LEFT(trans_date, 7) AS month,
    country, 
    COUNT(id) AS trans_count,
    COUNT(if(state = 'approved',1,NULL)) AS approved_count,
    SUM(amount) AS trans_total_amount,
    SUM(CASE WHEN state='approved' then amount else 0  end)  AS approved_total_amount
FROM 
    Transactions
GROUP BY 
    month, country;