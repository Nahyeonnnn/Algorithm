select category, price as max_price, product_name
from food_product
where (category, price) in (
    SELECT CATEGORY, max(price) as price
    from FOOD_PRODUCT
    WHERE category in ('과자', '국', '김치', '식용유') 
    group by CATEGORY
)
order by max_price desc

#     SELECT CATEGORY, max(price) as price
#     from FOOD_PRODUCT
#     WHERE category in ('과자', '국', '김치', '식용유') 
#     group by CATEGORY
    
    
    
    