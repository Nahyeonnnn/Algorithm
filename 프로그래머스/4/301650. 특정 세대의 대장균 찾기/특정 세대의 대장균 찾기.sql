with recursive cre_gen as (
    select ID, 1 as gen
    from ecoli_data
    where parent_id is null
    union all
    select e.ID, c.gen + 1
    from ecoli_data e join cre_gen c on e.parent_id = c.id
)

select id from cre_gen
where gen = 3
order by id;