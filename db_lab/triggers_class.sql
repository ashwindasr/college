create table t1(id int primary key);

create table t1_log(
        id int not null,
        logdate date
);

create or replace function t1LogEntry()
returns trigger as
$$
begin
        insert into t1_log values(new.id,now());
        return new;
end;
$$
language plpgsql;

create trigger t1_log_trigger before insert on t1 for each row execute procedure t1LogEntry();

insert into t1(id) values (1);

create table t1_backup(
        id int not null,
        logdate date
);

create trigger t1_backup_trigger before delete on t1 for each row execute procedure t1LogBackup();

create or replace function t1LogBackup()
returns trigger as
$$
begin
        insert into t1_backup values(old.id,now());
        return old;
end;
$$
language plpgsql;

delete from t1 where id=1;

BEFORE 
AFTER
INSTEAD
