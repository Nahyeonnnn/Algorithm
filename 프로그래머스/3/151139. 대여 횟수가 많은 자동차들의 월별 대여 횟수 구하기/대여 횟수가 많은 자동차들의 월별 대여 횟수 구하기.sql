SELECT month(START_DATE) as MONTH, CAR_ID, count(CAR_ID) as RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where car_id in (
    select car_id
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where '2022-08-01' <= START_DATE AND START_DATE <= '2022-10-31'
    group by car_id
    having count(car_id) >= 5 # 총 대여 횟수가 5회 이상
)
group by CAR_ID, month(START_DATE)
having count(CAR_ID) != 0 AND 8 <= MONTH AND MONTH <= 10 #  특정 월의 총 대여 횟수가 0인 경우 제외, 2022년 8월부터 2022년 10월까지 범위 다시 지정
order by month(START_DATE) asc, CAR_ID desc