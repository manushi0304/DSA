# Write your MySQL query statement belowselect twee
select tweet_id
from tweets
where char_length(content)>15;