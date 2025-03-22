select *
from (
    SELECT date_format(SALES_DATE, "%Y-%m-%d") as SALES_DATE, PRODUCT_ID, 
    USER_ID, SALES_AMOUNT
    from ONLINE_SALE
union all
    select date_format(SALES_DATE, "%Y-%m-%d") as SALES_DATE, PRODUCT_ID, 
    NULL as USER_ID, SALES_AMOUNT
    from OFFLINE_SALE
) u 
where year(u.SALES_DATE) = 2022 and month(u.sales_date) = 03
order by u.SALES_DATE, u.PRODUCT_ID, u.USER_ID