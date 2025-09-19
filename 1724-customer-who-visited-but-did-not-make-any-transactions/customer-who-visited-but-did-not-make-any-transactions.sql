# Write your MySQL query statement below
select customer_id,  COUNT(customer_id) AS count_no_trans
FROM Visits
left join transactions on visits.visit_id=transactions.visit_id
where transaction_id is NULL
group by customer_id;