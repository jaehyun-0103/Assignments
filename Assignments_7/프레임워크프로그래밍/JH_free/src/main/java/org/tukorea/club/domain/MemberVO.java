package org.tukorea.club.domain;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
public class MemberVO {
    private Integer memberId;
    private String memberName;
    private String email;
    private String password;
}
