-- 코드를 작성해주세요
select t.ITEM_ID, i.ITEM_NAME, i.RARITY
from ITEM_TREE t join ITEM_INFO i on t.ITEM_ID = i.ITEM_ID
where (select sum(PARENT_ITEM_ID)
       from ITEM_TREE
       where PARENT_ITEM_ID = t.ITEM_ID) is null
order by t.ITEM_ID desc;

# select sum(PARENT_ITEM_ID)
#        from ITEM_TREE
#        where PARENT_ITEM_ID = 0;