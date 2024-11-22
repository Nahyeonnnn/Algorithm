-- 코드를 입력하세요
SELECT FACTORY_ID, FACTORY_NAME, ADDRESS
from FOOD_FACTORY
where SUBSTR(ADDRESS, 1, 3) = '강원도';
# select substr('강원도 정선군 남면 칠현로 679',1 ,3);