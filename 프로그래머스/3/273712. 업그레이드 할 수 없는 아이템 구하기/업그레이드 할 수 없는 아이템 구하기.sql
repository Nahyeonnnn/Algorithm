select i.item_id, i.item_name, i.rarity
from item_info i
where not exists (
    select parent_item_id
    from item_tree
    where parent_item_id = i.item_id
)
order by i.item_id desc;