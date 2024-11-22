-- 코드를 입력하세요
SELECT FOOD_TYPE, REST_ID, REST_NAME, FAVORITES
from REST_INFO
where (FAVORITES, food_type) in (
    # 00001, 00004, 00003
    select max(FAVORITES), food_type
    from REST_INFO
    group by FOOD_TYPE
)
order by FOOD_TYPE desc;