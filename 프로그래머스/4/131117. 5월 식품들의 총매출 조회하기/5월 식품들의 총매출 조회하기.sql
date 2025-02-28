SELECT p.PRODUCT_ID, p.PRODUCT_NAME
, sum(amount) * p.price as TOTAL_SALES
from food_product p join food_order o on p.product_id=o.product_id
where YEAR(o.PRODUCE_DATE) = '2022' and month(o.PRODUCE_DATE)='5'
group by p.product_id
order by TOTAL_SALES desc, p.product_id asc