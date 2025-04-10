select c.car_id, c.car_type,
round(c.daily_fee * ((100-p.discount_rate)/100) * 30) as fee
from CAR_RENTAL_COMPANY_CAR c join CAR_RENTAL_COMPANY_DISCOUNT_PLAN p on c.car_type = p.car_type
where c.car_id not in (
    select car_id
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where (start_date <= '2022-11-01' and '2022-11-01' <= end_date) 
    or (start_date <= '2022-11-30' and '2022-11-30' <= end_date) 
)
and (c.car_type = 'SUV' or c.car_type = '세단')
and p.duration_type = '30일 이상'
and round(c.daily_fee * ((100-p.discount_rate)/100) * 30) < 2000000
and 500000 <= round(c.daily_fee * ((100-p.discount_rate)/100) * 30)
order by fee desc, c.car_type asc, c.car_id desc


# 26
# 16
# 29
# 5
# 17
# 19
# 12
# 7
# 15
# 8
# 6
# 21
# 1
# 4