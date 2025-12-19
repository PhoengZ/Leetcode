with first_login as(
	select player_id, min(event_date) as first_login from activity
	group by player_id
),
nums as (
	select count(*) as total from activity a join first_login f on a.player_id = f.player_id and f.first_login = a.event_date - 1
)
select round((select total from nums)::numeric / (select count(distinct player_id) from activity) ,2) as fraction