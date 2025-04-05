# SELECT hour(datetime) as HOUR, count(ANIMAL_ID) as COUNT
# from ANIMAL_OUTS
# group by hour(datetime)
# order by hour(datetime)

with recursive hour_cnt as (
    select 0 as hour
    union all
    select hour + 1
    from hour_cnt
    where hour < 23
)
select h.hour, ifnull(a.count, 0) as count
from hour_cnt h left join (
    SELECT hour(datetime) as HOUR, count(ANIMAL_ID) as COUNT
    from ANIMAL_OUTS
    group by hour(datetime)
) a on h.hour = a.hour
