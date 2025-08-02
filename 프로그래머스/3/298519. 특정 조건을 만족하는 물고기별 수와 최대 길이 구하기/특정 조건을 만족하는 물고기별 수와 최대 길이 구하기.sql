-- 종류별로 평균을 구하고, (이때 null을 어떻게 10으로 볼 것인지?)
-- max_length 구하고,
-- fish_type 구하기
select count(*) as FISH_COUNT, max(length) as MAX_LENGTH, FISH_TYPE
from fish_info
group by fish_type
having 33 <= avg(ifnull(length,10))
order by fish_type asc;

# select count(*) as FISH_COUNT, max(LENGTH) as MAX_LENGTH, FISH_TYPE
# from FISH_INFO
# group by FISH_TYPE
# having 33 <= avg(IFNULL(LENGTH,10))
# ORDER BY FISH_TYPE ASC;