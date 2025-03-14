SELECT c.CART_ID
from CART_PRODUCTS c
where exists (
    select *
    from CART_PRODUCTS
    where cart_id = c.cart_id and name = 'Milk'
) and exists (
    select *
    from cart_products
    where cart_id = c.cart_id and name = 'Yogurt'
)
group by cart_id
order by cart_id