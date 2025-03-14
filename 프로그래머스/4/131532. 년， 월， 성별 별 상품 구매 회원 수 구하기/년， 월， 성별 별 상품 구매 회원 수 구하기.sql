select t.year, t.month, t.gender, count(distinct user_id) as users
from (SELECT year(o.sales_date) as YEAR, month(o.sales_date) as MONTH, u.gender, u.user_id
from ONLINE_SALE o join USER_INFO u on o.user_id = u.user_id) t
group by t.year, t.month, t.gender
having t.gender is not null
order by t.year, t.month, t.gender;